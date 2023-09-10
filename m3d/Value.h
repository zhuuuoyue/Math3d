#pragma once

namespace m3d {

template<class T>
struct Value {

    Value()
        : undefined{ true } {
    }

    explicit Value(const T& value_)
        : value{ value_ }
        , undefined{ false } {
    }

    Value(const Value& other)
        : value{ other.value }
        , undefined{ other.undefined } {
    }

    Value& operator=(const Value& other) {
        value = other.value;
        undefined = other.undefined;
        return *this;
    }

    Value& operator=(const T& value_) {
        value = value_;
        undefined = false;
        return *this;
    }

    T value;
    bool undefined{ true };
};

using Int = Value<int>;
using Double = Value<double>;

}
