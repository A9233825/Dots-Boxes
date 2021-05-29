class Player{
    private:
        static int score;
    
    public:
        void setScore(){
            score++;
        }
        int getScore(){
            return score;
        }
};

int Player::score=0;