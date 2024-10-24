#pragma once
#include "Header.hpp"

namespace vk {

/**
 * @brief 单例类
 * @brief 用于管理Vulkan的基础类
 *
 */
class graphicsBase {
    static graphicsBase singleton;

    explicit graphicsBase() = default;
    graphicsBase(const graphicsBase &) = delete;
    graphicsBase(graphicsBase &&) = delete;
    ~graphicsBase() = default;

  public:
    static graphicsBase &Base() {
        return singleton;
    }

    /**
     * @brief Vulkan实例相关
     *
     */
  private:
    VkInstance instance;
    std::vector<const char *> instanceLayers;
    std::vector<const char *> instanceExtensions;

    /**
     * @brief 用于向容器中添加层或扩展 保证不重复
     *
     * @param container 加入容器
     * @param name 层或扩展名称
     */
    static void AddLayerOrExtension(std::vector<const char *> &container, const char *name) {
        for (auto &i : container)
            if (strcmp(i, name) == 0)
                return;
        container.push_back(name);
    }

  public:
    // Getters
    inline VkInstance GetInstance() const {
        return instance;
    }

    inline const std::vector<const char *> &InstanceLayers() const {
        return instanceLayers;
    }

    inline const std::vector<const char *> &InstanceExtensions() const {
        return instanceExtensions;
    }

    // Before Creating Instance
    void AddInstanceLayer(const char *name) {
        AddLayerOrExtension(instanceLayers, name);
    }

    void AddInstanceExtension(const char *name) {
        AddLayerOrExtension(instanceExtensions, name);
    }

    // Create Instance
    VkResult CreateInstance(VkInstanceCreateFlags flags = 0) {
    }

    // After Creating Instance (Failed)
    VkResult CheckInstanceLayers(std::span<const char *> layersToCheck) {
    }

    void InstanceLayers(const std::vector<const char *> &layerNames) {
        instanceLayers = layerNames;
    }

    VkResult CheckInstanceExtensions(std::span<const char *> extensionsToCheck) {
    }

    void InstanceExtensions(const std::vector<const char *> &extensionNames) {
        instanceExtensions = extensionNames;
    }
};
inline graphicsBase graphicsBase::singleton;

} // namespace vk

/*

Vulkan 初始化流程
1. 创建Vulkan实例
2. 创建debug messenger
3. 创建window surface

*/