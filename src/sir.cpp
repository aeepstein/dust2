// Generated by dust2 (version 0.1.8) - do not edit

#include <dust2/common.hpp>

// [[dust2::class(sir)]]
// [[dust2::time_type(discrete)]]
// [[dust2::has_compare()]]
// [[dust2::has_adjoint()]]
// [[dust2::parameter(I0)]]
// [[dust2::parameter(N)]]
// [[dust2::parameter(beta)]]
// [[dust2::parameter(gamma)]]
// [[dust2::parameter(exp_noise)]]
class sir {
public:
  sir() = delete;

  using real_type = double;

  struct shared_state {
    real_type N;
    real_type I0;
    real_type beta;
    real_type gamma;
    real_type exp_noise;
  };

  using internal_state = dust2::no_internal_state;

  struct data_type {
    real_type incidence;
  };

  using rng_state_type = monty::random::generator<real_type>;

  static dust2::packing packing_state(const shared_state& shared) {
    return dust2::packing{{"S", {}}, {"I", {}}, {"R", {}}, {"cases_cumul", {}}, {"cases_inc", {}}};
  }

  static void initial(real_type time,
                      real_type dt,
                      const shared_state& shared,
                      internal_state& internal,
                      rng_state_type& rng_state,
                      real_type * state_next) {
    state_next[0] = shared.N - shared.I0;
    state_next[1] = shared.I0;
    state_next[2] = 0;
    state_next[3] = 0;
    state_next[4] = 0;
  }

  // The main update function, converting state to state_next
  static void update(real_type time,
                     real_type dt,
                     const real_type * state,
                     const shared_state& shared,
                     internal_state& internal,
                     rng_state_type& rng_state,
                     real_type * state_next) {
    const auto S = state[0];
    const auto I = state[1];
    const auto R = state[2];
    const auto cases_cumul = state[3];
    const auto cases_inc = state[4];
    const auto p_SI = 1 - monty::math::exp(-shared.beta * I / shared.N * dt);
    const auto p_IR = 1 - monty::math::exp(-shared.gamma * dt);
    const auto n_SI = monty::random::binomial<real_type>(rng_state, S, p_SI);
    const auto n_IR = monty::random::binomial<real_type>(rng_state, I, p_IR);
    state_next[0] = S - n_SI;
    state_next[1] = I + n_SI - n_IR;
    state_next[2] = R + n_IR;
    state_next[3] = cases_cumul + n_SI;
    state_next[4] = cases_inc + n_SI;
  }

  static shared_state build_shared(cpp11::list pars) {
    const real_type I0 = dust2::r::read_real(pars, "I0", 10);
    const real_type N = dust2::r::read_real(pars, "N", 1000);
    const real_type beta = dust2::r::read_real(pars, "beta", 0.2);
    const real_type gamma = dust2::r::read_real(pars, "gamma", 0.1);
    const real_type exp_noise = dust2::r::read_real(pars, "exp_noise", 1e6);
    return shared_state{N, I0, beta, gamma, exp_noise};
  }

  static internal_state build_internal(const shared_state& shared) {
    return internal_state{};
  }

  // This is the bit that we'll use to do fast parameter updating, and
  // we'll guarantee somewhere that the size does not change.
  static void update_shared(cpp11::list pars, shared_state& shared) {
    shared.I0 = dust2::r::read_real(pars, "I0", shared.I0);
    shared.beta = dust2::r::read_real(pars, "beta", shared.beta);
    shared.gamma = dust2::r::read_real(pars, "gamma", shared.gamma);
  }

  // This is a reasonable default implementation in the no-internal
  // case
  static void update_internal(const shared_state& shared,
                              internal_state& internal) {
  }

  static auto zero_every(const shared_state& shared) {
    return dust2::zero_every_type<real_type>{{1, {4}}}; // zero[1] = {4};
  }

  static data_type build_data(cpp11::list r_data, const shared_state& shared) {
    auto data = static_cast<cpp11::list>(r_data);
    auto incidence = dust2::r::read_real(data, "incidence", NA_REAL);
    return data_type{incidence};
  }

  static real_type compare_data(const real_type time,
                                const real_type dt,
                                const real_type * state,
                                const data_type& data,
                                const shared_state& shared,
                                internal_state& internal,
                                rng_state_type& rng_state) {
    const auto incidence_observed = data.incidence;
    if (std::isnan(data.incidence)) {
      return 0;
    }
    const auto noise =
      monty::random::exponential_rate(rng_state, shared.exp_noise);
    const auto incidence_modelled = state[4];
    const auto lambda = incidence_modelled + noise;
    return monty::density::poisson(incidence_observed, lambda, true);
  }

  static dust2::packing packing_gradient(const shared_state& shared) {
    return dust2::packing{{"beta", {}}, {"gamma", {}}, {"I0", {}}};
  }

  static void adjoint_initial(real_type time,
                              real_type dt,
                              const real_type * state,
                              const real_type * adjoint,
                              const shared_state& shared,
                              internal_state& internal,
                              real_type * adjoint_next) {
    const real_type adj_I = adjoint[1];
    adjoint_next[0] = adjoint[0];
    adjoint_next[1] = adjoint[1];
    adjoint_next[2] = adjoint[2];
    adjoint_next[3] = adjoint[3];
    adjoint_next[4] = adjoint[4];
    adjoint_next[5] = adjoint[5];
    adjoint_next[6] = adjoint[6];
    adjoint_next[7] = adjoint[7] + adj_I;
  }

  static void adjoint_update(real_type time,
                             real_type dt,
                             const real_type * state,
                             const real_type * adjoint,
                             const shared_state& shared,
                             internal_state& internal,
                             real_type * adjoint_next) {
    const auto S = state[0];
    const auto I = state[1];

    const auto p_SI = 1 - monty::math::exp(-shared.beta * I / shared.N * dt);
    const auto p_IR = 1 - monty::math::exp(-shared.gamma * dt);

    const auto adj_S = adjoint[0];
    const auto adj_I = adjoint[1];
    const auto adj_R = adjoint[2];
    const auto adj_cases_cumul = adjoint[3];
    const auto adj_cases_inc = adjoint[4];
    const auto adj_beta = adjoint[5];
    const auto adj_gamma = adjoint[6];
    const auto adj_I0 = adjoint[7];

    const auto adj_lambda = 0;
    const auto adj_n_IR = -adj_I + adj_R;
    const auto adj_n_SI = adj_cases_inc + adj_cases_cumul + adj_I + -adj_S;
    const auto adj_p_IR = adj_n_IR * I;
    const auto adj_p_SI = adj_n_SI * S;

    adjoint_next[0] = adj_n_SI * p_SI + adj_S;
    adjoint_next[1] = adj_n_IR * p_IR + adj_p_SI * (shared.beta * dt) * monty::math::exp(-shared.beta * I * dt / shared.N) / shared.N + adj_I;
    adjoint_next[2] = adj_R;
    adjoint_next[3] = adj_cases_cumul;
    adjoint_next[4] = adj_lambda + adj_cases_inc * (dust2::tools::is_evenly_divisible_by(time, static_cast<real_type>(1)) ? 0 : 1);
    adjoint_next[5] = adj_beta + adj_p_SI * (I * dt) * monty::math::exp(-shared.beta * I * dt / shared.N) / shared.N;
    adjoint_next[6] = adj_gamma + adj_p_IR * monty::math::exp(-shared.gamma);
    adjoint_next[7] = adj_I0;
  }

  static void adjoint_compare_data(real_type time,
                                   real_type dt,
                                   const real_type * state,
                                   const real_type * adjoint,
                                   const data_type& data,
                                   const shared_state& shared,
                                   internal_state& internal,
                                   real_type * adjoint_next) {
    const real_type cases_inc = state[4];
    adjoint_next[0] = adjoint[0];
    adjoint_next[1] = adjoint[1];
    adjoint_next[2] = adjoint[2];
    adjoint_next[3] = adjoint[3];
    adjoint_next[4] = adjoint[4] + data.incidence / cases_inc - 1;
    adjoint_next[5] = adjoint[5];
    adjoint_next[6] = adjoint[6];
    adjoint_next[7] = adjoint[7];
  }
};

#include <cpp11.hpp>
#include <dust2/r/discrete/system.hpp>
#include <dust2/r/discrete/filter.hpp>
#include <dust2/r/discrete/unfilter.hpp>

[[cpp11::register]]
SEXP dust2_system_sir_alloc(cpp11::list r_pars, cpp11::sexp r_time, cpp11::sexp r_dt, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_seed, cpp11::sexp r_deterministic, cpp11::sexp r_n_threads) {
  return dust2::r::dust2_discrete_alloc<sir>(r_pars, r_time, r_dt, r_n_particles, r_n_groups, r_seed, r_deterministic, r_n_threads);
}
[[cpp11::register]]
SEXP dust2_system_sir_run_to_time(cpp11::sexp ptr, cpp11::sexp r_time) {
  return dust2::r::dust2_system_run_to_time<dust2::dust_discrete<sir>>(ptr, r_time);
}

[[cpp11::register]]
SEXP dust2_system_sir_state(cpp11::sexp ptr, cpp11::sexp r_index_state, cpp11::sexp r_index_particle, cpp11::sexp r_index_group, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_system_state<dust2::dust_discrete<sir>>(ptr, r_index_state, r_index_particle, r_index_group, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_system_sir_time(cpp11::sexp ptr) {
  return dust2::r::dust2_system_time<dust2::dust_discrete<sir>>(ptr);
}

[[cpp11::register]]
SEXP dust2_system_sir_set_state_initial(cpp11::sexp ptr) {
  return dust2::r::dust2_system_set_state_initial<dust2::dust_discrete<sir>>(ptr);
}

[[cpp11::register]]
SEXP dust2_system_sir_set_state(cpp11::sexp ptr, cpp11::sexp r_state, bool preserve_group_dimension) {
  return dust2::r::dust2_system_set_state<dust2::dust_discrete<sir>>(ptr, r_state, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_system_sir_reorder(cpp11::sexp ptr, cpp11::integers r_index) {
  return dust2::r::dust2_system_reorder<dust2::dust_discrete<sir>>(ptr, r_index);
}

[[cpp11::register]]
SEXP dust2_system_sir_rng_state(cpp11::sexp ptr) {
  return dust2::r::dust2_system_rng_state<dust2::dust_discrete<sir>>(ptr);
}

[[cpp11::register]]
SEXP dust2_system_sir_set_rng_state(cpp11::sexp ptr, cpp11::sexp r_rng_state) {
  return dust2::r::dust2_system_set_rng_state<dust2::dust_discrete<sir>>(ptr, r_rng_state);
}

[[cpp11::register]]
SEXP dust2_system_sir_set_time(cpp11::sexp ptr, cpp11::sexp r_time) {
  return dust2::r::dust2_system_set_time<dust2::dust_discrete<sir>>(ptr, r_time);
}

[[cpp11::register]]
SEXP dust2_system_sir_update_pars(cpp11::sexp ptr, cpp11::list pars) {
  return dust2::r::dust2_system_update_pars<dust2::dust_discrete<sir>>(ptr, pars);
}

[[cpp11::register]]
SEXP dust2_system_sir_simulate(cpp11::sexp ptr, cpp11::sexp r_times, cpp11::sexp r_index_state, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_system_simulate<dust2::dust_discrete<sir>>(ptr, r_times, r_index_state, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sir_alloc(cpp11::list r_pars, cpp11::sexp r_time_start, cpp11::sexp r_time, cpp11::sexp r_dt, cpp11::list r_data, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_n_threads, cpp11::sexp r_index_state) {
  return dust2::r::dust2_discrete_unfilter_alloc<sir>(r_pars, r_time_start, r_time, r_dt, r_data, r_n_particles, r_n_groups, r_n_threads, r_index_state);
}

[[cpp11::register]]
SEXP dust2_filter_sir_alloc(cpp11::list r_pars, cpp11::sexp r_time_start, cpp11::sexp r_time, cpp11::sexp r_dt, cpp11::list r_data, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_n_threads, cpp11::sexp r_index_state, cpp11::sexp r_seed) {
  return dust2::r::dust2_discrete_filter_alloc<sir>(r_pars, r_time_start, r_time, r_dt, r_data, r_n_particles, r_n_groups, r_n_threads, r_index_state, r_seed);
}
[[cpp11::register]]
SEXP dust2_system_sir_compare_data(cpp11::sexp ptr, cpp11::list r_data, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_system_compare_data<dust2::dust_discrete<sir>>(ptr, r_data, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sir_update_pars(cpp11::sexp ptr, cpp11::list r_pars, cpp11::sexp r_index_group) {
  return dust2::r::dust2_unfilter_update_pars<dust2::dust_discrete<sir>>(ptr, r_pars, r_index_group);
}

[[cpp11::register]]
SEXP dust2_unfilter_sir_run(cpp11::sexp ptr, cpp11::sexp r_initial, bool save_history, bool adjoint, cpp11::sexp r_index_group, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_unfilter_run<dust2::dust_discrete<sir>>(ptr, r_initial, save_history, adjoint, r_index_group, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sir_last_history(cpp11::sexp ptr, cpp11::sexp r_index_group, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_unfilter_last_history<dust2::dust_discrete<sir>>(ptr, r_index_group, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sir_last_state(cpp11::sexp ptr, cpp11::sexp r_index_group, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_unfilter_last_state<dust2::dust_discrete<sir>>(ptr, r_index_group, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sir_update_pars(cpp11::sexp ptr, cpp11::list r_pars, cpp11::sexp r_index_group) {
  return dust2::r::dust2_filter_update_pars<dust2::dust_discrete<sir>>(ptr, r_pars, r_index_group);
}

[[cpp11::register]]
SEXP dust2_filter_sir_run(cpp11::sexp ptr, cpp11::sexp r_initial, bool save_history, bool adjoint, cpp11::sexp index_group, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_filter_run<dust2::dust_discrete<sir>>(ptr, r_initial, save_history, adjoint, index_group, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sir_last_history(cpp11::sexp ptr, cpp11::sexp r_index_group, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_filter_last_history<dust2::dust_discrete<sir>>(ptr, r_index_group, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sir_last_state(cpp11::sexp ptr, cpp11::sexp r_index_group, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_filter_last_state<dust2::dust_discrete<sir>>(ptr, r_index_group, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sir_rng_state(cpp11::sexp ptr) {
  return dust2::r::dust2_filter_rng_state<dust2::dust_discrete<sir>>(ptr);
}

[[cpp11::register]]
SEXP dust2_filter_sir_set_rng_state(cpp11::sexp ptr, cpp11::sexp r_rng_state) {
  return dust2::r::dust2_filter_set_rng_state<dust2::dust_discrete<sir>>(ptr, r_rng_state);
}

[[cpp11::register]]
SEXP dust2_unfilter_sir_last_gradient(cpp11::sexp ptr, cpp11::sexp r_index_group, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_discrete_unfilter_last_gradient<dust2::dust_discrete<sir>>(ptr, r_index_group, preserve_particle_dimension, preserve_group_dimension);
}
