#include "threepp/threepp.hpp"

using namespace threepp;

int main() {
    // Create the rendering window
    Canvas canvas("Black Background Example");
    GLRenderer renderer{canvas.size()};
    renderer.setClearColor(Color::black); // Set the background color to black

    // Set up the scene and camera
    auto scene = Scene::create();
    auto camera = PerspectiveCamera::create(75, canvas.aspect(), 0.1f, 1000);
    camera->position.z = 5;

    // Render loop
    canvas.animate([&]() {
        renderer.render(*scene, *camera); // Render the scene with a black background
    });

    return 0;
}


