//
// Created by nazzazel on 24.07.2026.
//


#pragma once


#include "IEvent.hpp"


namespace engine
{


    class EventBus
    {
    public:
        // Template to subscribe a member function or lambda to a specific Event type
        template<typename T, typename Func>
        void Subscribe(Func&& callback)
        {
            // Store the callback wrapped in std::function, casted to accept the base Event
            auto wrapper = [cb = std::forward<Func>(callback)](IEvent& e) {
                cb(static_cast<T&>(e));
            };//lAMBDASS ARE COOL
            m_Subscribers[typeid(T)].push_back(wrapper);
        }

        // Push an event into the queue to be processed later during update
        template<typename T, typename... Args>
        void Emit(Args&&... args)
        {
            m_EventQueue.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        }

        // Call this inside your main update loop ("ring" or flush the queue)
        void ProcessEvents()
        {
            // Swap queues or process current items to handle events generated during processing
            std::vector<std::unique_ptr<IEvent>> eventsToProcess = std::move(m_EventQueue);
            m_EventQueue.clear();

            for (auto& event : eventsToProcess)
            {
                auto it = m_Subscribers.find(typeid(*event));
                if (it != m_Subscribers.end())
                {
                    for (auto& callback : it->second)
                    {
                        callback(*event);
                    }
                }
            }
        }

    private:
        // Map event type to a list of subscriber callbacks
        std::unordered_map<std::type_index, std::vector<std::function<void(IEvent&)>>> m_Subscribers;

        // The queue holding events until the update loop "rings" them
        std::vector<std::unique_ptr<IEvent>> m_EventQueue;
    };
}
