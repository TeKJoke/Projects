#ifndef ENTITY_H
#define ENTITY_H

typedef int hp;

class entity {
    public:
        virtual void cure() = 0;
        virtual void print_health() = 0;
};

#endif /* ifndef SYMBOL */
