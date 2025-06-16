/*
    Miscellaneous tutorials
    
    GLFW window
 */

#include <cstdlib>  // EXIT_FAILURE, EXIT_SUCCESS
#include <iostream> // std::cerr, std::endl

#include "scope_exit.hpp"
#include "glfw.hpp"

/* global constants */
static const int window_width = 800;
static const int window_height = 600;

/* application data */
struct App {
    Glfw glfw;
};


int main() {
    App app;
    SCOPE_EXIT{
        glfw_window_destroy( app.glfw );
        glfw_cleanup( app.glfw );
    }; /* lambda to cleanup on exit */


    try {
        glfw_init( app.glfw );
        glfw_window_create( app.glfw, window_width, window_height );
    }
    catch( const std::exception &ex ) {
        std::cerr
            << "[ERR] INIT: "
                << ex.what()
                << std::endl;

        return EXIT_FAILURE;
    }

    while( !glfw_should_close( app.glfw ) ) {
        glfw_poll_events( app.glfw );
    }

    return EXIT_SUCCESS;
}
