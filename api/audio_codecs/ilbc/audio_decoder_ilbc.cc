/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "api/audio_codecs/ilbc/audio_decoder_ilbc.h"

#include <memory>
#include <optional>
#include <vector>

#include "absl/strings/match.h"
#include "api/audio_codecs/audio_codec_pair_id.h"
#include "api/audio_codecs/audio_decoder.h"
#include "api/audio_codecs/audio_format.h"
#include "api/field_trials_view.h"
#include "modules/audio_coding/codecs/ilbc/audio_decoder_ilbc.h"

namespace webrtc {

std::optional<AudioDecoderIlbc::Config> AudioDecoderIlbc::SdpToConfig(
    const SdpAudioFormat& format) {
  if (absl::EqualsIgnoreCase(format.name, "ILBC") &&
      format.clockrate_hz == 8000 && format.num_channels == 1) {
    return Config();
  }
  return std::nullopt;
}

void AudioDecoderIlbc::AppendSupportedDecoders(
    std::vector<AudioCodecSpec>* specs) {
  // RingRTC change to disable unused audio codecs
  // specs->push_back({{"ILBC", 8000, 1}, {8000, 1, 13300}});
}

std::unique_ptr<AudioDecoder> AudioDecoderIlbc::MakeAudioDecoder(
    Config config,
    std::optional<AudioCodecPairId> /*codec_pair_id*/,
    const FieldTrialsView* field_trials) {
  return std::make_unique<AudioDecoderIlbcImpl>();
}

}  // namespace webrtc
