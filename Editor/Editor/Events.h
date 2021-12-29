#pragma once
#include "Delegates.h"
namespace Editor
{
    template <typename... Args>
    public ref class Event
    {
    public:
        delegate void Handler(Args...);
        void operator+=(Handler^ d)
        {
            del += d;
        }
        void operator-=(Handler^ d)
        {
            del -= d;
        }
        void operator()(Args... args) {
            if (del) {
                del->Invoke(args...);
            }
        }
        template<typename... CArgs>
        Handler^ create_handler(CArgs... args)
        {
            return gcnew Handler(args...);
        }
    private:
        Handler^ del;
    };




	ref class EditorEvents
	{
	public:
        static Event<Entity> on_selected_entity_changed;

	};
}