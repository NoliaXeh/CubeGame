#include <iostream>

class Block
{
    public:
        Block();
        Block(const Block& block) = default;
        Block(char r, char g, char b, float opacity, int id);
        Block& operator=(const Block& block) = default;
        void render_at(double x, double y, double z);
        void print();

    private:
        struct
        {
            char r;
            char g;
            char b;
        } color_;
        float opacity_;
        int id_;
};
