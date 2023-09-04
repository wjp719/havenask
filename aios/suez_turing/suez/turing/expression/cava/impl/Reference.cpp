/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "suez/turing/expression/cava/impl/Reference.h"

#include <iosfwd>
#include <string>

#include "autil/MultiValueType.h"
#include "matchdoc/Reference.h"
#include "suez/turing/expression/cava/impl/MatchDoc.h"

class CavaCtx;
namespace ha3 {
class MChar;
} // namespace ha3
namespace matchdoc {
class MatchDoc;
} // namespace matchdoc

using namespace std;

namespace unsafe {

#define SET_SINGLE_VALUE_WITH_TYPE(name, type)                                                                         \
    void Reference::set##name(CavaCtx *ctx, ha3::MatchDoc *doc, type val) {                                            \
        auto *ref = (matchdoc::Reference<type> *)this;                                                                 \
        return ref->set(*(matchdoc::MatchDoc *)doc, val);                                                              \
    }

SET_SINGLE_VALUE_WITH_TYPE(Int8, int8_t);
SET_SINGLE_VALUE_WITH_TYPE(Int16, int16_t);
SET_SINGLE_VALUE_WITH_TYPE(Int32, int32_t);
SET_SINGLE_VALUE_WITH_TYPE(Int64, int64_t);
SET_SINGLE_VALUE_WITH_TYPE(UInt8, uint8_t);
SET_SINGLE_VALUE_WITH_TYPE(UInt16, uint16_t);
SET_SINGLE_VALUE_WITH_TYPE(UInt32, uint32_t);
SET_SINGLE_VALUE_WITH_TYPE(UInt64, uint64_t);
SET_SINGLE_VALUE_WITH_TYPE(Float, float);
SET_SINGLE_VALUE_WITH_TYPE(Double, double);

void Reference::setMChar(CavaCtx *ctx, ha3::MatchDoc *doc, ha3::MChar *val) {
    auto *ref = (matchdoc::Reference<autil::MultiChar> *)this;
    autil::MultiChar multiChar(val);
    ref->set(*(matchdoc::MatchDoc *)doc, multiChar);
}

void Reference::setSTLString(CavaCtx *ctx, ha3::MatchDoc *doc, ha3::MChar *val) {
    auto *ref = (matchdoc::Reference<std::string> *)this;
    autil::MultiChar multiChar(val);
    ref->set(*(matchdoc::MatchDoc *)doc, std::string(multiChar.data(), multiChar.size()));
}

#undef SET_SINGLE_VALUE_WITH_TYPE

} // namespace unsafe
