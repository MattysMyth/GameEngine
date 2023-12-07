# Rendering Engine
The Rendering Engine is designed to host all the Graphics API agnostic calls to manage rendering
images to the monitor.

## Structure
### Update function
The Rendering Engine will receive any new or removed entities from the GameEngine itself, update the
data to be rendered and pass this data to the GPU.

### Draw function
The function dedicated solely to making draw calls to the GPU. The intended effect of having a single 
function to handle all draw coomunication to the GPU is to make optimising more seamless when
prioritising what specifically is drawn per call, ultimately aiming to reduce the number of calls
necessary.