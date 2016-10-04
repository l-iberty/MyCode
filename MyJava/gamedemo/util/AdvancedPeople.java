package gamedemo.util;

public class AdvancedPeople extends People {
	private String status = "Ninjia ";
	private String weapon = "[sword]";
	private int extraATK = 15;

	@Override
	public String getStatus() {
		return status;
	}

	@Override
	public void showInfo() {
		GameFrame.attackPrecess.append(status + name + "\'s HP is " + HP + "\n");
		GameFrame.attackPrecess.append(status + name + "\'s ATK is " + ATK +
					"; extra ATK comming from " + weapon + " is " + extraATK + "\n");
	}

	@Override
	public void showAttack(People opponent) {
		int finalATK = ATK + extraATK;
		opponent.setHP(opponent.getHP() - finalATK);
		GameFrame.attackPrecess.append( "\n" + status + name + " attacked " +  opponent.getStatus() + opponent.getName() +
					" using " + weapon + ", " + opponent.getStatus() + opponent.getName() + " suffered " + finalATK +
					 " points of damage," + " with " + opponent.getHP() + " points of HP lefted.\n");
	}
}