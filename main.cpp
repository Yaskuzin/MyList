#include <iostream>

template< class T>
class value {
    T my_value;
    value<T> *next;
    value<T> *previous;
    int number;
public:
    value<T> *getNext() const {
        return next;
    }

    value<T> *getPrevious() const {
        return previous;
    }

    T getMy_value() const {
        return my_value;
    }

    void setNumber(int number) {
        value::number = number;
    }

    void setNext(value<T> *next) {
        value::next = next;
    }

    void setPrevious(value<T> *previous) {
        value::previous = previous;
    }

    int getNumber() const {
        return number;
    }

    value(T my_value, value<T> *next, value<T> *previous, int number) : my_value(my_value), next(next),
                                                                        previous(previous), number(number) {}
};

    template< class T>
    class stack{
    private:
        value<T>* next;
        value<T>* previous;
        int size;
    public:
        stack(value<T> *next,value<T> *previous) : next(next) ,previous(previous),size(0) {}

    public:
        void add(T newValue, int number){
            if (number<size){
                while (previous != nullptr && previous->getNumber() != number){
                    next = previous;
                    previous = next->getPrevious();
                }
                value<T>* between = new value<T>(newValue,next,previous,number);
                next->setPrevious(between);
                previous->setNext(between);
                while (next->getNext() != 0){
                    next->setNumber(next->getNumber()+1);
                    next = next->getNext();
                }
            }
            else {
                previous = next;
                value<T> *NEXT = new value<T>(newValue, 0, previous, number);
                next = NEXT;
            }
            size++;
        }

        value<T> *getNext() const {
            return next;
        }

        value<T> *getPrevious() const {
            return previous;
        }

        int getSize() const {
            return size;
        }
    };

int main() {
    stack<int>* my_list = new stack<int>(nullptr,nullptr);
    my_list->add(10,1);
    my_list->add(20,2);
    my_list->add(30,2);
    my_list->add(30,1);
    std::cout <<  my_list->getSize()<< std::endl;
    return 0;
}