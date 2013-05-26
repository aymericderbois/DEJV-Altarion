#ifndef GAMEINFORMATION_HH
#define	GAMEINFORMATION_HH

namespace Game
{

    class GameInformation
    {
    public:
        GameInformation();
        virtual ~GameInformation();
    private:
        int currentPage;
    public:
        void SetCurrentPage(int currentPage);
        int GetCurrentPage() const;
    };

    enum Pages
    {
        MENU,
        IN_GAME,
    };
}

#endif	/* GAMEINFORMATION_HH */

