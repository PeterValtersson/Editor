using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EditorWPF
{
    public class Entity
    {
        public delegate void NameChanged(String name);
        public event NameChanged OnNameChanged;
        private UInt32 value;
        public Entity(UInt32 value)
        {
            this.value = value;
        }

        public static implicit operator Entity(UInt32 value)
        {
            return new Entity(value);
        }
     
        public static implicit operator UInt32(Entity value)
        {
            return value.value;
        }
        private String name;
        public String Name
        {
            get => name;
            set
            {
                name = value;
                if (OnNameChanged is not null)
                    OnNameChanged(name);
            }
        }
    }
}
