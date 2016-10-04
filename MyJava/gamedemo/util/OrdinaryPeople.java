package gamedemo.util;

public class OrdinaryPeople extends People {
	private String status = "Ordinary-People ";

	@Override
	public String getStatus() {
		return status;
	}

	@Override
	public void showInfo() {
		GameFrame.attackPrecess.append(status + name + "\'s HP is " + HP + "\n");
		GameFrame.attackPrecess.append(status + name + "\'s ATK is " + ATK + "\n");
	}

	@Override
	public void showAttack(People opponent) {
		opponent.setHP(opponent.getHP() - ATK);
		GameFrame.attackPrecess.append("\n" + status + name + " attacked " + opponent.getStatus() + opponent.getName() +
					", "  + opponent.getStatus() + opponent.getName() + " suffered " + ATK + " points of damage," +
					" with " + opponent.getHP() + " points of HP lefted.\n");
	}
}