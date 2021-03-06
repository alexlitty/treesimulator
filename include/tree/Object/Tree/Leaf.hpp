#ifndef TREESIMULATOR_OBJECT_TREE_LEAF
#define TREESIMULATOR_OBJECT_TREE_LEAF

#include <set>
#include <tree/Component.hpp>
#include <tree/Chemistry.hpp>
#include <tree/Math.hpp>

namespace tree
{
    class Leaf : public Drawable
    {
        // Object this leaf is attached to.
        Physical* parent;

        // Molecule composing this leaf.
        Molecule molecule;

        // Shape of the leaf.
        sf::VertexArray vertices;

        // Shooting threshold ticker.
        Ticker shootThresholdTicker;

        // Enemies currently being shocked.
        std::set<tree::Lifeform*> enemiesShocked;

    public:

        // Relative position of the leaf.
        Vector position;

        /**
         * Constructor.
         */
        Leaf(Physical* _parent, Vector _position, Molecule _molecule);

        /**
         * Act.
         */
        void act();

        /**
         * Shoots weapons.
         */
        void shoot(Angle angle, std::vector<Lifeform*> &enemies, std::vector<Weapon*> &weapons);

        /**
         * Draws the leaf.
         */
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
}

#endif
