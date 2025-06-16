
#include <iostream>     // std::errr, std:endl
#include <stdexcept>    // std::runtime_error

#include "glfw.hpp"

/* Print error GLFW message */
static void glfw_error_callback( int error,
                                 const char* description ) {
    std::cerr
        << "[ERR] GLFW: "
            << description
            << std::endl;
}

/* ESC - close application
 */
static void key_callback( GLFWwindow* window,
                          int key,
                          int scancode,
                          int action,
                          int mods ) {
    if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
        glfwSetWindowShouldClose( window, GLFW_TRUE );
}

void glfw_init( Glfw &glfw ) {
    glfw.init = false;
    glfw.window_ptr = nullptr;

    /* setup an error callback function */
    (void)glfwSetErrorCallback( glfw_error_callback );

    /* initialize GLFW library*/
    if( glfwInit() != GLFW_TRUE )
        throw std::runtime_error( "GLFW initialization fail" );

    glfw.init = true;
}

void glfw_cleanup( Glfw &glfw ) {
    if( !glfw.init )
        return;

    glfwTerminate();
    glfw.init = false;
}

void glfw_window_create( Glfw &glfw, int width, int height ) {
    if( !glfw.init )
        throw std::runtime_error( "GLFW wasn't initialized" );

    /* don't create any graphical context */
    glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );

    glfw.window_ptr = glfwCreateWindow(
        width
      , height
      , "Miscellaneous Tutorial - GLFW Window"  /* window title */
      , nullptr                                 /* actual monitor for full screen app */
      , nullptr                                 /* window to share context with */
    );
    if( !glfw.window_ptr )
        throw std::runtime_error( "GLFW Window creation fail" );

    /* capture keyboard input */
    (void)glfwSetKeyCallback(
        glfw.window_ptr
      , key_callback
    );
}

void glfw_window_destroy( Glfw &glfw ) {
    if( !glfw.init )
        return;
    if( !glfw.window_ptr )
        return;

    glfwDestroyWindow( glfw.window_ptr );
    glfw.window_ptr = nullptr;
}

bool glfw_should_close( Glfw &glfw ) {
    return( !!glfwWindowShouldClose( glfw.window_ptr ) );
}

void glfw_poll_events( [[maybe_unused]] Glfw &glfw ) {
    glfwPollEvents();
}
