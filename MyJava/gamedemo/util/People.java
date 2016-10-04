package gamedemo.util;

import java.util.Random;

public class People {
	protected String name;
	private Random random = new Random();
	protected int HP = (random.nextInt(2000)) % (2000-1000) + 1000;
	protected int ATK = (random.nextInt(15)) % (15-10) + 10;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getHP() {
		return (HP > 0) ? HP : 0;
	}

	public void setHP(int HP) {
		this.HP = HP;
	}

	public int getATK() {
		return ATK;
	}

	public String getStatus() {
		return null;
	}

	public void showInfo() {
		GameFrame.attackPrecess.append(name + "\'s HP is " + HP + "\n");
		GameFrame.attackPrecess.append(name + "\'s ATK is " + ATK + "\n");
	}

	public void showAttack(People opponent) {
		opponent.setHP(opponent.getHP() - ATK);
		GameFrame.attackPrecess.append("\n" + name + " attacked " + opponent.getName() + ", " +
					opponent.getName() + " suffered " + ATK + " points of damage," +
					" with " + opponent.getHP() + " points of HP lefted.\n");
	}

	public void showJudgement(People opponent) {
		if (HP <= 0) {
			GameFrame.attackPrecess.append("\n" + opponent.getName() + " won!\n");
		}
	}
}