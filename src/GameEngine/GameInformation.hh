#ifndef GAMEINFORMATION_HH
#define	GAMEINFORMATION_HH

namespace Game
{

    class GameInformation
    {
    public:
        GameInformation();
        virtual ~GameInformation();
        bool isInMenu();
        bool isInGame();
    private:
        int currentPage;
    public:
        void setCurrentPage(int currentPage);
        int getCurrentPage() const;
    };

    enum Pages
    {
        MENU,
        IN_GAME,
    };
}

#endif	/* GAMEINFORMATION_HH */

