// Generated by dust2 (version 0.3.5) - do not edit

#include <dust2/common.hpp>

// [[dust2::class(sirode)]]
// [[dust2::time_type(continuous)]]
// [[dust2::has_compare()]]
// [[dust2::parameter(I0, rank = 0, constant = FALSE, required = FALSE)]]
// [[dust2::parameter(N, rank = 0, constant = TRUE, required = FALSE)]]
// [[dust2::parameter(beta, rank = 0, constant = FALSE, required = FALSE)]]
// [[dust2::parameter(gamma, rank = 0, constant = FALSE, required = FALSE)]]
class sirode {
public:
  sirode() = delete;

  using real_type = double;

  struct shared_state {
    real_type N;
    real_type I0;
    real_type beta;
    real_type gamma;
  };

  struct internal_state {};

  struct data_type {
    real_type incidence;
  };

  using rng_state_type = monty::random::generator<real_type>;

  static dust2::packing packing_state(const shared_state& shared) {
    return dust2::packing{{"S", {}}, {"I", {}}, {"R", {}}, {"cases_cumul", {}}, {"cases_inc", {}}};
  }

  static void initial(real_type time,
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

  static void rhs(real_type time,
                  const real_type * state,
                  const shared_state& shared,
                  internal_state& internal,
                  real_type * state_deriv) {
    const auto S = state[0];
    const auto I = state[1];
    const auto rate_SI = shared.beta * S * I / shared.N;
    const auto rate_IR = shared.gamma * I;
    state_deriv[0] = -rate_SI;
    state_deriv[1] = rate_SI - rate_IR;
    state_deriv[2] = rate_IR;
    state_deriv[3] = rate_SI;
    state_deriv[4] = rate_SI;
  }

  static shared_state build_shared(cpp11::list pars) {
    const real_type I0 = dust2::r::read_real(pars, "I0", 10);
    const real_type N = dust2::r::read_real(pars, "N", 1000);
    const real_type beta = dust2::r::read_real(pars, "beta", 0.2);
    const real_type gamma = dust2::r::read_real(pars, "gamma", 0.1);
    return shared_state{N, I0, beta, gamma};
  }

  // This is the bit that we'll use to do fast parameter updating, and
  // we'll guarantee somewhere that the size does not change.
  static void update_shared(cpp11::list pars, shared_state& shared) {
    shared.I0 = dust2::r::read_real(pars, "I0", shared.I0);
    shared.beta = dust2::r::read_real(pars, "beta", shared.beta);
    shared.gamma = dust2::r::read_real(pars, "gamma", shared.gamma);
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
                                const real_type * state,
                                const data_type& data,
                                const shared_state& shared,
                                internal_state& internal,
                                rng_state_type& rng_state) {
    const auto incidence_observed = data.incidence;
    if (std::isnan(data.incidence)) {
      return 0;
    }
    const auto incidence_modelled = state[4];
    return monty::density::poisson(incidence_observed, incidence_modelled, true);
  }
};

#include <cpp11.hpp>
#include <dust2/r/continuous/system.hpp>
#include <dust2/r/continuous/filter.hpp>
#include <dust2/r/continuous/unfilter.hpp>

[[cpp11::register]]
SEXP dust2_system_sirode_alloc(cpp11::list r_pars, cpp11::sexp r_time, cpp11::list r_time_control, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_seed, cpp11::sexp r_deterministic, cpp11::sexp r_n_threads) {
  return dust2::r::dust2_continuous_alloc<sirode>(r_pars, r_time, r_time_control, r_n_particles, r_n_groups, r_seed, r_deterministic, r_n_threads);
}

[[cpp11::register]]
SEXP dust2_system_sirode_internals(cpp11::sexp ptr, bool include_coefficients, bool include_history) {
  return dust2::r::dust2_system_internals<dust2::dust_continuous<sirode>>(ptr, include_coefficients, include_history);
}
[[cpp11::register]]
SEXP dust2_system_sirode_run_to_time(cpp11::sexp ptr, cpp11::sexp r_time) {
  return dust2::r::dust2_system_run_to_time<dust2::dust_continuous<sirode>>(ptr, r_time);
}

[[cpp11::register]]
SEXP dust2_system_sirode_state(cpp11::sexp ptr, cpp11::sexp r_index_state, cpp11::sexp r_index_particle, cpp11::sexp r_index_group, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_system_state<dust2::dust_continuous<sirode>>(ptr, r_index_state, r_index_particle, r_index_group, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_system_sirode_time(cpp11::sexp ptr) {
  return dust2::r::dust2_system_time<dust2::dust_continuous<sirode>>(ptr);
}

[[cpp11::register]]
SEXP dust2_system_sirode_set_state_initial(cpp11::sexp ptr) {
  return dust2::r::dust2_system_set_state_initial<dust2::dust_continuous<sirode>>(ptr);
}

[[cpp11::register]]
SEXP dust2_system_sirode_set_state(cpp11::sexp ptr, cpp11::list r_state) {
  return dust2::r::dust2_system_set_state<dust2::dust_continuous<sirode>>(ptr, r_state);
}

[[cpp11::register]]
SEXP dust2_system_sirode_reorder(cpp11::sexp ptr, cpp11::integers r_index) {
  return dust2::r::dust2_system_reorder<dust2::dust_continuous<sirode>>(ptr, r_index);
}

[[cpp11::register]]
SEXP dust2_system_sirode_rng_state(cpp11::sexp ptr) {
  return dust2::r::dust2_system_rng_state<dust2::dust_continuous<sirode>>(ptr);
}

[[cpp11::register]]
SEXP dust2_system_sirode_set_rng_state(cpp11::sexp ptr, cpp11::sexp r_rng_state) {
  return dust2::r::dust2_system_set_rng_state<dust2::dust_continuous<sirode>>(ptr, r_rng_state);
}

[[cpp11::register]]
SEXP dust2_system_sirode_set_time(cpp11::sexp ptr, cpp11::sexp r_time) {
  return dust2::r::dust2_system_set_time<dust2::dust_continuous<sirode>>(ptr, r_time);
}

[[cpp11::register]]
SEXP dust2_system_sirode_update_pars(cpp11::sexp ptr, cpp11::list pars) {
  return dust2::r::dust2_system_update_pars<dust2::dust_continuous<sirode>>(ptr, pars);
}

[[cpp11::register]]
SEXP dust2_system_sirode_simulate(cpp11::sexp ptr, cpp11::sexp r_times, cpp11::sexp r_index_state, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_system_simulate<dust2::dust_continuous<sirode>>(ptr, r_times, r_index_state, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sirode_alloc(cpp11::list r_pars, cpp11::sexp r_time_start, cpp11::sexp r_time, cpp11::list r_time_control, cpp11::list r_data, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_n_threads) {
  return dust2::r::dust2_continuous_unfilter_alloc<sirode>(r_pars, r_time_start, r_time, r_time_control, r_data, r_n_particles, r_n_groups, r_n_threads);
}

[[cpp11::register]]
SEXP dust2_filter_sirode_alloc(cpp11::list r_pars, cpp11::sexp r_time_start, cpp11::sexp r_time, cpp11::list r_time_control, cpp11::list r_data, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_n_threads, cpp11::sexp r_seed) {
  return dust2::r::dust2_continuous_filter_alloc<sirode>(r_pars, r_time_start, r_time, r_time_control, r_data, r_n_particles, r_n_groups, r_n_threads, r_seed);
}
[[cpp11::register]]
SEXP dust2_system_sirode_compare_data(cpp11::sexp ptr, cpp11::list r_data, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_system_compare_data<dust2::dust_continuous<sirode>>(ptr, r_data, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sirode_update_pars(cpp11::sexp ptr, cpp11::list r_pars, cpp11::sexp r_index_group) {
  return dust2::r::dust2_unfilter_update_pars<dust2::dust_continuous<sirode>>(ptr, r_pars, r_index_group);
}

[[cpp11::register]]
SEXP dust2_unfilter_sirode_run(cpp11::sexp ptr, cpp11::sexp r_initial, bool save_history, bool adjoint, cpp11::sexp r_index_state, cpp11::sexp r_index_group, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_unfilter_run<dust2::dust_continuous<sirode>>(ptr, r_initial, save_history, adjoint, r_index_state, r_index_group, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sirode_last_trajectories(cpp11::sexp ptr, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_unfilter_last_trajectories<dust2::dust_continuous<sirode>>(ptr, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_unfilter_sirode_last_state(cpp11::sexp ptr, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_unfilter_last_state<dust2::dust_continuous<sirode>>(ptr, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sirode_update_pars(cpp11::sexp ptr, cpp11::list r_pars, cpp11::sexp r_index_group) {
  return dust2::r::dust2_filter_update_pars<dust2::dust_continuous<sirode>>(ptr, r_pars, r_index_group);
}

[[cpp11::register]]
SEXP dust2_filter_sirode_run(cpp11::sexp ptr, cpp11::sexp r_initial, bool save_history, bool adjoint, cpp11::sexp index_state, cpp11::sexp index_group, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_filter_run<dust2::dust_continuous<sirode>>(ptr, r_initial, save_history, adjoint, index_state, index_group, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sirode_last_trajectories(cpp11::sexp ptr, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_filter_last_trajectories<dust2::dust_continuous<sirode>>(ptr, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sirode_last_state(cpp11::sexp ptr, bool select_random_particle, bool preserve_particle_dimension, bool preserve_group_dimension) {
  return dust2::r::dust2_filter_last_state<dust2::dust_continuous<sirode>>(ptr, select_random_particle, preserve_particle_dimension, preserve_group_dimension);
}

[[cpp11::register]]
SEXP dust2_filter_sirode_rng_state(cpp11::sexp ptr) {
  return dust2::r::dust2_filter_rng_state<dust2::dust_continuous<sirode>>(ptr);
}

[[cpp11::register]]
SEXP dust2_filter_sirode_set_rng_state(cpp11::sexp ptr, cpp11::sexp r_rng_state) {
  return dust2::r::dust2_filter_set_rng_state<dust2::dust_continuous<sirode>>(ptr, r_rng_state);
}
