/*
 * Copyright (c) 2020 Bytedance Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * @authors Jianqiang Guo, Yuhui Su
 */
#ifndef SateFactory_H_
#define SateFactory_H_

#include "State.h"
#include "../Base.h"
#include "Element.h"

namespace fastbotx {

    class StateFactory {
    public:

        static StatePtr
        createState(AlgorithmType agentT, const stringPtr &activity, const ElementPtr &element);
    };
}
#endif /* SateFactory_H_ */