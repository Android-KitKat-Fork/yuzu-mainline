// Copyright 2020 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <cstddef>
#include <vector>

#include "video_core/renderer_vulkan/vk_resource_pool.h"
#include "video_core/renderer_vulkan/wrapper.h"

namespace Vulkan {

class MasterSemaphore;
class VKDevice;

class CommandPool final : public ResourcePool {
public:
    explicit CommandPool(MasterSemaphore& master_semaphore, const VKDevice& device);
    virtual ~CommandPool();

    void Allocate(size_t begin, size_t end) override;

    VkCommandBuffer Commit();

private:
    struct Pool {
        vk::CommandPool handle;
        vk::CommandBuffers cmdbufs;
    };

    const VKDevice& device;
    std::vector<Pool> pools;
};

} // namespace Vulkan
