#ifndef REVENANT_SCRIPT_H
#define REVENANT_SCRIPT_H

namespace revenant
{
    class Script
    {
    public:
        virtual ~Script() noexcept = default;
        Script(Script const&) = delete;
        Script(Script&&) = delete;
        Script& operator=(Script const&) = delete;
        Script& operator=(Script&&) = delete;

        virtual bool IsInitialized() = 0;
        virtual void Initialize() = 0;
        virtual void Destroy() = 0;
        virtual void Tick() = 0;
    protected:
        Script() = default;
    };
}

#endif //REVENANT_SCRIPT_H