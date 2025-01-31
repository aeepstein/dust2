#include <dust2/common.hpp>

#ifdef _OPENMP
#include <omp.h>
#endif

template <typename real_type>
real_type thread_id() {
#ifdef _OPENMP
    return static_cast<real_type>(omp_get_thread_num());
#else
    return -1;
#endif
}

// [[dust2::class(openmp)]]
// [[dust2::time_type(discrete)]]
class openmp {
public:
  openmp() = delete;

  using real_type = double;
  struct shared_state {};
  struct internal_state {};
  using rng_state_type = monty::random::generator<real_type>;

  static dust2::packing packing_state(const shared_state& shared) {
    return dust2::packing{{"x", {}}};
  }

  static void update_shared(cpp11::list pars, shared_state& shared) {
  }

  static void initial(real_type time,
                      const shared_state& shared,
                      internal_state& internal,
                      rng_state_type& rng_state,
                      real_type * state_next) {
    state_next[0] = thread_id<real_type>();
  }

  static void update(real_type time,
                     real_type dt,
                     const real_type * state,
                     const shared_state& shared,
                     internal_state& internal,
                     rng_state_type& rng_state,
                     real_type * state_next) {
    state_next[0] = thread_id<real_type>();
  }

  static shared_state build_shared(cpp11::list pars) {
    return shared_state{};
  }
};
