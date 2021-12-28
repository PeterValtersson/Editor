#pragma once
#include "Delegates.h"
namespace Editor
{
    public ref class OnSelectedEntityChanged
    {
    public:
        void operator+=(SelectedEntityChanged^ d)
        {
            del += d;
        }
        void operator-=(SelectedEntityChanged^ d)
        {
            del -= d;
        }
        void operator()(Entity ent) {
            if (del) {
                del->Invoke(ent);
            }
        }
    private:
        SelectedEntityChanged^ del;
    };

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