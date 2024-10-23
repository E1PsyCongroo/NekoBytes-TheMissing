#include "tower.h"

/*按正确的顺序与参数，调用tower_move函数
将一大小为n的盘子为底的一摞大小连续的盘子从from柱移动到to柱子，中继柱为via*/
void hanoi(int n, char from, char to, char via);