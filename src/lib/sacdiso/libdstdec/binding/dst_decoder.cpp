/*
* SACD Decoder plugin
* Copyright (c) 2011-2023 Maxim V.Anisiutkin <maxim.anisiutkin@gmail.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with FFmpeg; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "dst_decoder.h"
#include "decoder.h"
#include "dst_engine.h"

typedef dst_engine_t<dst::decoder_t, model_e::MT> ctx_t;

static auto ctx_cast = [](auto ctx) {
	return static_cast<ctx_t*>(ctx);
};

dst_decoder_t::dst_decoder_t(size_t num_threads) {
	ctx = static_cast<void*>(new ctx_t(num_threads));
}

dst_decoder_t::~dst_decoder_t() {
	delete ctx_cast(ctx);
}

bool dst_decoder_t::is_init() {
	return ctx && ctx_cast(ctx)->is_init();
}

int dst_decoder_t::init(unsigned int channels, unsigned int channel_frame_size) {
	return ctx_cast(ctx)->init(channels, channel_frame_size);
}

size_t dst_decoder_t::run(std::vector<unsigned char>& dsx_data) {
	return ctx_cast(ctx)->run(dsx_data);
}