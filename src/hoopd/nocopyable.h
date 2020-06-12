#ifndef HOOPD_NONCOPYABLE_HPP
#define HOOPD_NONCOPYABLE_HPP

namespace hoopd {

//  Private copy constructor and copy assignment ensure classes derived from
//  class noncopyable cannot be copied.

namespace noncopyable_  // protection from unintended ADL
{
#ifndef HOOPD_NONCOPYABLE_BASE_TOKEN_DEFINED
#define HOOPD_NONCOPYABLE_BASE_TOKEN_DEFINED

// noncopyable derives from base_token to enable Type Traits to detect
// whether a type derives from noncopyable without needing the definition
// of noncopyable itself.
//
// The definition of base_token is macro-guarded so that Type Trais can
// define it locally without including this header, to avoid a dependency
// on Core.

  struct base_token {};

#endif // #ifndef HOOPD_NONCOPYABLE_BASE_TOKEN_DEFINED

class noncopyable: base_token
{
protected:
    explicit noncopyable() = default;
    ~noncopyable() = default;
    noncopyable( const noncopyable& ) = delete;
    noncopyable& operator=( const noncopyable& ) = delete;
    noncopyable(noncopyable&& moved) = delete;
    noncopyable& operator=(noncopyable&&) = delete;
};
}

typedef noncopyable_::noncopyable noncopyable;

} // namespace hoopd

#endif  // HOOPD_NONCOPYABLE_HPP