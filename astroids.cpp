#include "threepp/threepp.hpp"
#include "threepp/loaders/OBJLoader.hpp"
#include <memory>
#include <valarray>

#include "threepp/canvas/Canvas.hpp"
#include "threepp/core/Object3D.hpp"
#include "keys for movment.hpp"

class SpaceshipController;
class Projectile;
using namespace threepp;


int main() {
    // Create the rendering window
    Canvas canvas("Top-Down View of Spaceship");
    GLRenderer renderer{canvas.size()};
    renderer.setClearColor(Color::black);

    // Create the scene and camera
    auto scene = Scene::create();

    // Set up a camera positioned above and looking down
    auto camera = PerspectiveCamera::create(75, canvas.aspect(), 0.1f, 1000);
    camera->position.set(0, 5, 0);         // Position the camera above the spaceship
    camera->lookAt(Vector3(0, 0, 0));      // Make the camera look down towards the origin

    // Load the OBJ model
    auto spaceship = OBJLoader().load("Fighter_01.obj"); // Adjust the path as necessary
    spaceship->scale.set(0.08, 0.08, 0.08);  // Scale the model if needed
    spaceship->rotation.x = (std::numbers::pi) / 1;    // Rotate the model to face the top view
    scene->add(spaceship);

    // Lighting (optional)
    auto light = DirectionalLight::create(0xffffff, 1.0);
    light->position.set(5, 5, 5);
    scene->add(light);


    float moveSpeed =0.2f ; // Adjust movement speed as needed
    float rotationSpeed = 0.00f; // Adjust rotation speed as needed


    // Initialize the spaceship controller
    SpaceshipController controller;
    canvas.addKeyListener(controller);


    // Animation loop
    canvas.animate([&]()
    {
        // Handle movement
        if (controller.rotateRight) {
            spaceship->position.x += moveSpeed * std::cos(spaceship->rotation.z);
            spaceship->position.y += moveSpeed * std::sin(spaceship->rotation.z);
        }
        if (controller.rotateLeft) {
            spaceship->position.x -= moveSpeed * std::cos(spaceship->rotation.z);
            spaceship->position.y -= moveSpeed * std::sin(spaceship->rotation.z);
        }
        if (controller.moveForward) {
            spaceship->rotation.z += rotationSpeed;
        }
        if (controller.moveBackward) {
            spaceship->rotation.z -= rotationSpeed;
        }

        renderer.render(*scene, *camera);
    });

    return 0;
}











//
// Created by abdul on 11/12/2024.
//
