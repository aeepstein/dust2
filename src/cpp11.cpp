// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// sir.cpp
SEXP dust2_cpu_sir_alloc(cpp11::list r_pars, cpp11::sexp r_time, cpp11::sexp r_dt, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_seed, cpp11::sexp r_deterministic);
extern "C" SEXP _dust2_dust2_cpu_sir_alloc(SEXP r_pars, SEXP r_time, SEXP r_dt, SEXP r_n_particles, SEXP r_n_groups, SEXP r_seed, SEXP r_deterministic) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_alloc(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(r_pars), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_dt), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_particles), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_groups), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_seed), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_deterministic)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_run_steps(cpp11::sexp ptr, cpp11::sexp r_n_steps);
extern "C" SEXP _dust2_dust2_cpu_sir_run_steps(SEXP ptr, SEXP r_n_steps) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_run_steps(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_steps)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_run_to_time(cpp11::sexp ptr, cpp11::sexp r_time);
extern "C" SEXP _dust2_dust2_cpu_sir_run_to_time(SEXP ptr, SEXP r_time) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_run_to_time(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_state(cpp11::sexp ptr, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_state(SEXP ptr, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_time(cpp11::sexp ptr);
extern "C" SEXP _dust2_dust2_cpu_sir_time(SEXP ptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_time(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_set_time(cpp11::sexp ptr, cpp11::sexp r_time);
extern "C" SEXP _dust2_dust2_cpu_sir_set_time(SEXP ptr, SEXP r_time) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_set_time(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_update_pars(cpp11::sexp ptr, cpp11::list pars, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_update_pars(SEXP ptr, SEXP pars, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_update_pars(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(pars), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_set_state_initial(cpp11::sexp ptr);
extern "C" SEXP _dust2_dust2_cpu_sir_set_state_initial(SEXP ptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_set_state_initial(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_set_state(cpp11::sexp ptr, cpp11::sexp r_state, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_set_state(SEXP ptr, SEXP r_state, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_set_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_state), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_reorder(cpp11::sexp ptr, cpp11::integers r_index);
extern "C" SEXP _dust2_dust2_cpu_sir_reorder(SEXP ptr, SEXP r_index) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_reorder(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(r_index)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_rng_state(cpp11::sexp ptr);
extern "C" SEXP _dust2_dust2_cpu_sir_rng_state(SEXP ptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_rng_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_set_rng_state(cpp11::sexp ptr, cpp11::sexp r_rng_state);
extern "C" SEXP _dust2_dust2_cpu_sir_set_rng_state(SEXP ptr, SEXP r_rng_state) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_set_rng_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_rng_state)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_compare_data(cpp11::sexp ptr, cpp11::sexp r_data, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_compare_data(SEXP ptr, SEXP r_data, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_compare_data(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_data), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_simulate(cpp11::sexp ptr, cpp11::sexp r_times, cpp11::sexp r_index, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_simulate(SEXP ptr, SEXP r_times, SEXP r_index, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_simulate(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_times), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_index), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_unfilter_alloc(cpp11::list r_pars, cpp11::sexp r_time_start, cpp11::sexp r_time, cpp11::sexp r_dt, cpp11::list r_data, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_index);
extern "C" SEXP _dust2_dust2_cpu_sir_unfilter_alloc(SEXP r_pars, SEXP r_time_start, SEXP r_time, SEXP r_dt, SEXP r_data, SEXP r_n_particles, SEXP r_n_groups, SEXP r_index) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_unfilter_alloc(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(r_pars), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time_start), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_dt), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(r_data), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_particles), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_groups), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_index)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_unfilter_run(cpp11::sexp ptr, cpp11::sexp r_pars, cpp11::sexp r_initial, bool save_history, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_unfilter_run(SEXP ptr, SEXP r_pars, SEXP r_initial, SEXP save_history, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_unfilter_run(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_pars), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_initial), cpp11::as_cpp<cpp11::decay_t<bool>>(save_history), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_unfilter_last_history(cpp11::sexp ptr, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_unfilter_last_history(SEXP ptr, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_unfilter_last_history(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_filter_alloc(cpp11::list r_pars, cpp11::sexp r_time_start, cpp11::sexp r_time, cpp11::sexp r_dt, cpp11::list r_data, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_index, cpp11::sexp r_seed);
extern "C" SEXP _dust2_dust2_cpu_sir_filter_alloc(SEXP r_pars, SEXP r_time_start, SEXP r_time, SEXP r_dt, SEXP r_data, SEXP r_n_particles, SEXP r_n_groups, SEXP r_index, SEXP r_seed) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_filter_alloc(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(r_pars), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time_start), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_dt), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(r_data), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_particles), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_groups), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_index), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_seed)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_filter_run(cpp11::sexp ptr, cpp11::sexp r_pars, cpp11::sexp r_initial, bool save_history, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_filter_run(SEXP ptr, SEXP r_pars, SEXP r_initial, SEXP save_history, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_filter_run(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_pars), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_initial), cpp11::as_cpp<cpp11::decay_t<bool>>(save_history), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_filter_last_history(cpp11::sexp ptr, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_sir_filter_last_history(SEXP ptr, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_filter_last_history(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// sir.cpp
SEXP dust2_cpu_sir_filter_rng_state(cpp11::sexp ptr);
extern "C" SEXP _dust2_dust2_cpu_sir_filter_rng_state(SEXP ptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_sir_filter_rng_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr)));
  END_CPP11
}
// test.cpp
cpp11::integers test_resample_weight(std::vector<double> w, double u);
extern "C" SEXP _dust2_test_resample_weight(SEXP w, SEXP u) {
  BEGIN_CPP11
    return cpp11::as_sexp(test_resample_weight(cpp11::as_cpp<cpp11::decay_t<std::vector<double>>>(w), cpp11::as_cpp<cpp11::decay_t<double>>(u)));
  END_CPP11
}
// test.cpp
cpp11::list test_scale_log_weights(std::vector<double> w);
extern "C" SEXP _dust2_test_scale_log_weights(SEXP w) {
  BEGIN_CPP11
    return cpp11::as_sexp(test_scale_log_weights(cpp11::as_cpp<cpp11::decay_t<std::vector<double>>>(w)));
  END_CPP11
}
// test.cpp
cpp11::sexp test_history(cpp11::doubles r_time, cpp11::list r_state, cpp11::sexp r_order, bool reorder);
extern "C" SEXP _dust2_test_history(SEXP r_time, SEXP r_state, SEXP r_order, SEXP reorder) {
  BEGIN_CPP11
    return cpp11::as_sexp(test_history(cpp11::as_cpp<cpp11::decay_t<cpp11::doubles>>(r_time), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(r_state), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_order), cpp11::as_cpp<cpp11::decay_t<bool>>(reorder)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_alloc(cpp11::list r_pars, cpp11::sexp r_time, cpp11::sexp r_dt, cpp11::sexp r_n_particles, cpp11::sexp r_n_groups, cpp11::sexp r_seed, cpp11::sexp r_deterministic);
extern "C" SEXP _dust2_dust2_cpu_walk_alloc(SEXP r_pars, SEXP r_time, SEXP r_dt, SEXP r_n_particles, SEXP r_n_groups, SEXP r_seed, SEXP r_deterministic) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_alloc(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(r_pars), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_dt), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_particles), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_groups), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_seed), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_deterministic)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_run_steps(cpp11::sexp ptr, cpp11::sexp r_n_steps);
extern "C" SEXP _dust2_dust2_cpu_walk_run_steps(SEXP ptr, SEXP r_n_steps) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_run_steps(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_n_steps)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_run_to_time(cpp11::sexp ptr, cpp11::sexp r_time);
extern "C" SEXP _dust2_dust2_cpu_walk_run_to_time(SEXP ptr, SEXP r_time) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_run_to_time(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_state(cpp11::sexp ptr, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_walk_state(SEXP ptr, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_time(cpp11::sexp ptr);
extern "C" SEXP _dust2_dust2_cpu_walk_time(SEXP ptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_time(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_set_state_initial(cpp11::sexp ptr);
extern "C" SEXP _dust2_dust2_cpu_walk_set_state_initial(SEXP ptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_set_state_initial(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_set_state(cpp11::sexp ptr, cpp11::sexp r_state, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_walk_set_state(SEXP ptr, SEXP r_state, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_set_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_state), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_reorder(cpp11::sexp ptr, cpp11::integers r_index);
extern "C" SEXP _dust2_dust2_cpu_walk_reorder(SEXP ptr, SEXP r_index) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_reorder(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(r_index)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_rng_state(cpp11::sexp ptr);
extern "C" SEXP _dust2_dust2_cpu_walk_rng_state(SEXP ptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_rng_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_set_rng_state(cpp11::sexp ptr, cpp11::sexp r_rng_state);
extern "C" SEXP _dust2_dust2_cpu_walk_set_rng_state(SEXP ptr, SEXP r_rng_state) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_set_rng_state(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_rng_state)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_set_time(cpp11::sexp ptr, cpp11::sexp r_time);
extern "C" SEXP _dust2_dust2_cpu_walk_set_time(SEXP ptr, SEXP r_time) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_set_time(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_time)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_update_pars(cpp11::sexp ptr, cpp11::list pars, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_walk_update_pars(SEXP ptr, SEXP pars, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_update_pars(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(pars), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}
// walk.cpp
SEXP dust2_cpu_walk_simulate(cpp11::sexp ptr, cpp11::sexp r_times, cpp11::sexp r_index, bool grouped);
extern "C" SEXP _dust2_dust2_cpu_walk_simulate(SEXP ptr, SEXP r_times, SEXP r_index, SEXP grouped) {
  BEGIN_CPP11
    return cpp11::as_sexp(dust2_cpu_walk_simulate(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(ptr), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_times), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(r_index), cpp11::as_cpp<cpp11::decay_t<bool>>(grouped)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_dust2_dust2_cpu_sir_alloc",                 (DL_FUNC) &_dust2_dust2_cpu_sir_alloc,                 7},
    {"_dust2_dust2_cpu_sir_compare_data",          (DL_FUNC) &_dust2_dust2_cpu_sir_compare_data,          3},
    {"_dust2_dust2_cpu_sir_filter_alloc",          (DL_FUNC) &_dust2_dust2_cpu_sir_filter_alloc,          9},
    {"_dust2_dust2_cpu_sir_filter_last_history",   (DL_FUNC) &_dust2_dust2_cpu_sir_filter_last_history,   2},
    {"_dust2_dust2_cpu_sir_filter_rng_state",      (DL_FUNC) &_dust2_dust2_cpu_sir_filter_rng_state,      1},
    {"_dust2_dust2_cpu_sir_filter_run",            (DL_FUNC) &_dust2_dust2_cpu_sir_filter_run,            5},
    {"_dust2_dust2_cpu_sir_reorder",               (DL_FUNC) &_dust2_dust2_cpu_sir_reorder,               2},
    {"_dust2_dust2_cpu_sir_rng_state",             (DL_FUNC) &_dust2_dust2_cpu_sir_rng_state,             1},
    {"_dust2_dust2_cpu_sir_run_steps",             (DL_FUNC) &_dust2_dust2_cpu_sir_run_steps,             2},
    {"_dust2_dust2_cpu_sir_run_to_time",           (DL_FUNC) &_dust2_dust2_cpu_sir_run_to_time,           2},
    {"_dust2_dust2_cpu_sir_set_rng_state",         (DL_FUNC) &_dust2_dust2_cpu_sir_set_rng_state,         2},
    {"_dust2_dust2_cpu_sir_set_state",             (DL_FUNC) &_dust2_dust2_cpu_sir_set_state,             3},
    {"_dust2_dust2_cpu_sir_set_state_initial",     (DL_FUNC) &_dust2_dust2_cpu_sir_set_state_initial,     1},
    {"_dust2_dust2_cpu_sir_set_time",              (DL_FUNC) &_dust2_dust2_cpu_sir_set_time,              2},
    {"_dust2_dust2_cpu_sir_simulate",              (DL_FUNC) &_dust2_dust2_cpu_sir_simulate,              4},
    {"_dust2_dust2_cpu_sir_state",                 (DL_FUNC) &_dust2_dust2_cpu_sir_state,                 2},
    {"_dust2_dust2_cpu_sir_time",                  (DL_FUNC) &_dust2_dust2_cpu_sir_time,                  1},
    {"_dust2_dust2_cpu_sir_unfilter_alloc",        (DL_FUNC) &_dust2_dust2_cpu_sir_unfilter_alloc,        8},
    {"_dust2_dust2_cpu_sir_unfilter_last_history", (DL_FUNC) &_dust2_dust2_cpu_sir_unfilter_last_history, 2},
    {"_dust2_dust2_cpu_sir_unfilter_run",          (DL_FUNC) &_dust2_dust2_cpu_sir_unfilter_run,          5},
    {"_dust2_dust2_cpu_sir_update_pars",           (DL_FUNC) &_dust2_dust2_cpu_sir_update_pars,           3},
    {"_dust2_dust2_cpu_walk_alloc",                (DL_FUNC) &_dust2_dust2_cpu_walk_alloc,                7},
    {"_dust2_dust2_cpu_walk_reorder",              (DL_FUNC) &_dust2_dust2_cpu_walk_reorder,              2},
    {"_dust2_dust2_cpu_walk_rng_state",            (DL_FUNC) &_dust2_dust2_cpu_walk_rng_state,            1},
    {"_dust2_dust2_cpu_walk_run_steps",            (DL_FUNC) &_dust2_dust2_cpu_walk_run_steps,            2},
    {"_dust2_dust2_cpu_walk_run_to_time",          (DL_FUNC) &_dust2_dust2_cpu_walk_run_to_time,          2},
    {"_dust2_dust2_cpu_walk_set_rng_state",        (DL_FUNC) &_dust2_dust2_cpu_walk_set_rng_state,        2},
    {"_dust2_dust2_cpu_walk_set_state",            (DL_FUNC) &_dust2_dust2_cpu_walk_set_state,            3},
    {"_dust2_dust2_cpu_walk_set_state_initial",    (DL_FUNC) &_dust2_dust2_cpu_walk_set_state_initial,    1},
    {"_dust2_dust2_cpu_walk_set_time",             (DL_FUNC) &_dust2_dust2_cpu_walk_set_time,             2},
    {"_dust2_dust2_cpu_walk_simulate",             (DL_FUNC) &_dust2_dust2_cpu_walk_simulate,             4},
    {"_dust2_dust2_cpu_walk_state",                (DL_FUNC) &_dust2_dust2_cpu_walk_state,                2},
    {"_dust2_dust2_cpu_walk_time",                 (DL_FUNC) &_dust2_dust2_cpu_walk_time,                 1},
    {"_dust2_dust2_cpu_walk_update_pars",          (DL_FUNC) &_dust2_dust2_cpu_walk_update_pars,          3},
    {"_dust2_test_history",                        (DL_FUNC) &_dust2_test_history,                        4},
    {"_dust2_test_resample_weight",                (DL_FUNC) &_dust2_test_resample_weight,                2},
    {"_dust2_test_scale_log_weights",              (DL_FUNC) &_dust2_test_scale_log_weights,              1},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_dust2(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
