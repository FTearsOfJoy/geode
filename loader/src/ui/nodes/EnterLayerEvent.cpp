#include <Geode/ui/EnterLayerEvent.hpp>

using namespace geode::prelude;

AEnterLayerEvent::AEnterLayerEvent(
    std::string const& layerID,
    cocos2d::CCNode* layer
) : layerID(layerID),
    layer(layer) {}

ListenerResult AEnterLayerFilter::handle(std::function<Callback> fn, AEnterLayerEvent* event) {
    if (m_targetID.has_value()) {
        if (event->layerID == m_targetID.value()) {
            fn(event);
        }
    }
    else {
        fn(event);
    }
    return ListenerResult::Propagate;
}

AEnterLayerFilter::AEnterLayerFilter(
    std::optional<std::string> const& id
) : m_targetID(id) {}
