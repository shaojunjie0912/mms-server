/*
MIT License

Copyright (c) 2021 jiangbaolin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <string>
#include "amf0/amf0_inc.hpp"
#include "rtmp_define.hpp"
#include "rtmp_fcpublish_message.hpp"
namespace mms {
class RtmpFCPublishRespMessage {
public:
    RtmpFCPublishRespMessage(const RtmpFCPublishMessage & rel_msg, const std::string & name);
    RtmpFCPublishRespMessage();
    virtual ~RtmpFCPublishRespMessage();
public:
    int32_t decode(std::shared_ptr<RtmpMessage> rtmp_msg);
    std::shared_ptr<RtmpMessage> encode() const;

    Amf0Null & cmdObj() {
        return command_obj_;
    }

private:
    Amf0String command_name_;
    Amf0Number transaction_id_;
    Amf0Null command_obj_;
    Amf0Undefined udef_;
};
};