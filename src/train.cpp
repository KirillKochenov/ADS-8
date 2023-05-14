// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
    first = nullptr;
    countOp = 0;
}
void Train::addCage(bool light) {
    Cage *cage = new Cage{light, nullptr, nullptr};
    if (first == nullptr) {
        first = cage;
        first->next = first;
        first->prev = first;
    } else {
        Cage *last = first->prev;
        last->next = cage;
        cage->prev = last;
        cage->next = first;
        first->prev = cage;
    }
    countOp = 0;
}
int Train::getLength() {
    int len = 0;
    int steps = 0;
    Cage* reserved = new Cage;
    reserved = first;
    reserved->next = first->next;
    reserved->prev = first->prev;
    if (!first->light) {
        first->light = true;
    }
    while (1) {
        reserved = reserved->next;
        steps++;
        countOp++;
        if (reserved->light) {
            reserved->light = false;
            int backup = steps;
            while (steps) {
                reserved = reserved->prev;
                --steps;
                countOp++;
            }
            if (!first->light) {
                return backup;
            }
        }
    }
    return 0;
}
int Train::getOpCount() {
    return countOp;
}
