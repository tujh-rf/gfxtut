/* Small helper class to destroy all resources on exit
    from the current scope */

#include <functional>

#ifndef SCOPE_EXIT_HPP
#define SCOPE_EXIT_HPP


/*! scope guard class - will capture any functional objects,
    and call it from the destructor */
class scope_exit {
public:
    /* object MUST not be copied */
    scope_exit() = delete;
    scope_exit( const scope_exit& ) = delete;
    scope_exit( scope_exit&& ) = delete;
    scope_exit& operator = ( const scope_exit& ) = delete;
    scope_exit& operator = ( scope_exit&& ) = delete;


    /* capture the functional object */
    template< typename _Tp >
    scope_exit( const _Tp &scope_guard ):
        m_scope_guard( scope_guard ) {
    }
    /* destroy the guard and call captured functional object */
    ~scope_exit() {
        m_scope_guard();
    }

private:
    std::function< void() > m_scope_guard;  //!< simplest functional object

};

/*! helper to create the lambda called on the exit from the scope */
#define SCOPE_EXIT scope_exit guard = [&]()


#endif /* SCOPE_EXIT_HPP */
