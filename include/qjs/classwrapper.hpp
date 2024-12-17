#pragma once

#include "classwrapper_fwd.hpp"
#include "quickjs.h"

namespace Qjs {
    template <typename T>
    void ClassWrapper<T>::SetProto(Value proto) {
        JS_SetClassProto(proto.ctx, GetClassId(proto.ctx.rt), proto.ToUnmanaged());
    }

    template <typename T>
    T *ClassWrapper<T>::Get(Value value) {
        return static_cast<T *>(JS_GetOpaque(value, GetClassId(value.ctx.rt)));
    }
}