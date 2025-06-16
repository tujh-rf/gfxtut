/* Wrapper on the GLFW library */

#include <GLFW/glfw3.h>

#ifndef GLFW_STRUCT_HPP
#define GLFW_STRUCT_HPP


/* structure with GLFW data */
struct Glfw {
    bool        init        { false };      //!< flag of GLFW initialization
    GLFWwindow *window_ptr  { nullptr };    //!< pointer to the GLFW window
};


/*! Initialize the wrapper */
void glfw_init( Glfw &glfw );

/*! Cleanup the wrapper */
void glfw_cleanup( Glfw &glfw );

/*! Create GLFW window */
void glfw_window_create( Glfw &glfw, int width, int height );

/*! Destroy GLFW window */
void glfw_window_destroy( Glfw &glfw );

/*! Test if the application should close */
bool glfw_should_close( Glfw &glfw );

/*! poll and proceed system events */
void glfw_poll_events( Glfw &glfw );


#endif /* GLFW_STRUCT_HPP */
