/*
Copyright 2017 VMware, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef _XDPMODEL_H_
#define _XDPMODEL_H_

#include "backends/ebpf/ebpfModel.h"

namespace XDP {

struct XDP_Switch_Model : public ::Model::Elem {
    XDP_Switch_Model() : Elem("xdp"),
                     parser("p"), swtch("s"), deparser("d") {}
    ::Model::Elem parser;
    ::Model::Elem swtch;
    ::Model::Elem deparser;
};

// Keep this in sync with xdp_model.p4
class XDPModel : public EBPF::EBPFModel {
 protected:
    XDPModel() : EBPF::EBPFModel(), xdp()
    {}

 public:
    static XDPModel instance;
    XDP_Switch_Model xdp;
};

}  // namespace XDP

#endif /* _XDPMODEL_H_ */
