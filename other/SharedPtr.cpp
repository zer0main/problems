/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

struct Foo {
public:
    Foo() {
        std::cout << "Foo's constructor." << std::endl;
    }

    Foo(int n) {
        std::cout << "Foo's int constructor." << std::endl;
    }

    ~Foo() {
        std::cout << "Foo's destructor." << std::endl;
    }
};

template<typename T>
class SharedPtr {
private:
    struct Storage {
        int counter;
        T* obj;
    };

    Storage* storage_;

public:
    SharedPtr():
        storage_(0) {
        reset();
    }

    explicit SharedPtr(T* obj):
        storage_(0) {
        reset(obj);
    }

    SharedPtr(const SharedPtr& ptr):
        storage_(0) {
        reset(ptr);
    }

    ~SharedPtr() {
        reset();
    }

    bool empty() {
        return storage_ == 0;
    }

    void reset() {
        if (storage_ != 0) {
            storage_->counter -= 1;
            if (storage_->counter == 0) {
                delete storage_->obj;
                delete storage_;
            }
            storage_ = 0;
        }
    }

    void reset(T* t) {
        reset();
        if (t != 0) {
            storage_ = new Storage();
            storage_->obj = t;
            storage_->counter = 1;
        }
    }

    void reset(const SharedPtr& ptr) {
        reset();
        if (ptr.storage_ != 0) {
            storage_ = ptr.storage_;
            storage_->counter += 1;
        }
    }

    SharedPtr& operator=(const SharedPtr& ptr) {
        reset(ptr);
        return *this;
    }
};

template<typename D>
SharedPtr<D> makeShared(int arg) {
    SharedPtr<D> ptr = SharedPtr<Foo>(new D(arg));
    return ptr;
}

int main() {
    std::cout << "zer0main's shared pointer" << std::endl;
    SharedPtr<Foo> foo_ptr = SharedPtr<Foo>(new Foo());
    std::cout << "foo_ptr is empty: " << foo_ptr.empty() << std::endl;
    SharedPtr<Foo> foo_ptr2 = foo_ptr;
    std::cout << "foo_ptr is empty: " << foo_ptr.empty() << std::endl;
    foo_ptr.reset();
    std::cout << "foo_ptr is empty: " << foo_ptr.empty() << std::endl;
    foo_ptr.reset(new Foo());
    std::cout << "foo_ptr is empty: " << foo_ptr.empty() << std::endl;
    foo_ptr.reset(foo_ptr2);
    SharedPtr<Foo> foo_ptr3;
    std::cout << "foo_ptr3 is empty: " << foo_ptr3.empty() << std::endl;
    foo_ptr3 = foo_ptr2;
    std::cout << "foo_ptr3 is empty: " << foo_ptr3.empty() << std::endl;
    SharedPtr<Foo> foo_ptr4 = makeShared<Foo>(2);
    std::cout << "foo_ptr4 is empty: " << foo_ptr4.empty() << std::endl;
    return 0;
}
