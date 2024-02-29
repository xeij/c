#include "engine/window_context_handler.hpp"
#include "engine/physics/physics.hpp"
#include "renderer.hpp"
#include "wind.hpp"
#include "utils.hpp"


int main()
{
    const uint32_t window_width  = 1920;
    const uint32_t window_height = 1080;
    WindowContextHandler app("Cloth", sf::Vector2u(window_width, window_height), sf::Style::Default);
    PhysicSolver solver;
    Renderer renderer(solver);
    const uint32_t cloth_width  = 75;
    const uint32_t cloth_height = 50;
    const float    links_length = 20.0f;
    const float    start_x      = (window_width - (cloth_width - 1) * links_length) * 0.5f;
    for (uint32_t y(0); y < cloth_height; ++y) {
    
        const float max_elongation = 1.2f * (2.0f - to<float>(y) / float(cloth_height));
        for (uint32_t x(0); x < cloth_width; ++x) {
            const civ::ID id = solver.addParticle(
                sf::Vector2f(start_x + to<float>(x) * links_length, to<float>(y) * links_length)
            );
            if (x > 0) {
                solver.addLink(id-1, id, max_elongation * 0.9f);
            }
            if (y > 0) {
                solver.addLink(id-cloth_width, id, max_elongation);
            } else {
                solver.objects[id].moving = false;
            }
        }
    }

    sf::Vector2f last_mouse_position;
    bool dragging = false;
    bool erasing = false;
    app.getEventManager().addMousePressedCallback(sf::Mouse::Right, [&](sfev::CstEv) {
        dragging = true;
        last_mouse_position = app.getWorldMousePosition();
    });
    app.getEventManager().addMouseReleasedCallback(sf::Mouse::Right, [&](sfev::CstEv) {
        dragging = false;
    });
    app.getEventManager().addMousePressedCallback(sf::Mouse::Middle, [&](sfev::CstEv) {
        erasing = true;
    });
    app.getEventManager().addMouseReleasedCallback(sf::Mouse::Middle, [&](sfev::CstEv) {
        erasing = false;
    });

    // Add 2 wind waves
    WindManager wind(to<float>(window_width));
    wind.winds.emplace_back(
        sf::Vector2f(100.0f, window_height),
        sf::Vector2f(0.0f, 0.0f),
        sf::Vector2f(1000.0f, 0.0f)
    );
    wind.winds.emplace_back(
        sf::Vector2f(20.0f, window_height),
        sf::Vector2f(0.0f, 0.0f),
        sf::Vector2f(3000.0f, 0.0f)
    );

    const float dt = 1.0f / 60.0f;
    while (app.run()) {
        const sf::Vector2f mouse_position = app.getWorldMousePosition();

        if (dragging) {
            const sf::Vector2f mouse_speed = mouse_position - last_mouse_position;
            last_mouse_position = mouse_position;
            usr::Utils::applyForceOnCloth(mouse_position, 100.0f, mouse_speed * 8000.0f, solver);
        }

        if (erasing) {
            solver.objects.remove_if([&](const Particle& p) {return usr::Utils::isInRadius(p, mouse_position, 10.0f);});
        }
        // Update physics
        wind.update(solver, dt);
        solver.update(dt);
        RenderContext& render_context = app.getRenderContext();
        render_context.clear();
        renderer.render(render_context);
        render_context.display();
    }

    return 0;
}