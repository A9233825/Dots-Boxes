class Player{
    private:
        int score;
    
    public:
    	Player(){
    		score=0;
		}
        void setScore(){
            score++;
        }
        int getScore(){
            return score;
        }
};
