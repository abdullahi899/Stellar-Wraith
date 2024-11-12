
#include "threepp/threepp.hpp"

class SpaceshipController : public threepp::KeyListener {
public:
    bool moveForward = false;
    bool moveBackward = false;
    bool rotateLeft = false;
    bool rotateRight = false;
    bool firing = false;

    void onKeyPressed(threepp::KeyEvent evt) override {
        switch (evt.key) {
            case threepp::Key::W:
                moveForward = true;
            break;
            case threepp::Key::S:
                moveBackward = true;
            break;
            case threepp::Key::A:
                rotateLeft = true;
            break;
            case threepp::Key::D:
                rotateRight = true;
            break;
            case threepp::Key::SPACE:
                firing = true;
            break;
            default:
                break;
        }
    }

    void onKeyReleased(threepp::KeyEvent evt) override {
        switch (evt.key) {
            case threepp::Key::W:
                moveForward = false;
            break;
            case threepp::Key::S:
                moveBackward = false;
            break;
            case threepp::Key::A:
                rotateLeft = false;
            break;
            case threepp::Key::D:
                rotateRight = false;
            break;
            case threepp::Key::SPACE:
                firing = false;
            break;
            default:
                break;
        }
    }
};









//
// Created by abdul on 11/12/2024.
//

#ifndef KEYS_FOR_MOVMENT_H
#define KEYS_FOR_MOVMENT_H

#endif //KEYS_FOR_MOVMENT_H
