# Sprague-Grundy Function SG函数

## 定义

![SG函数的定义](F:\develop\xcpc\src\topics\game-theory\sg-function\assets\SG函数的定义.png)

## 例子

![取子游戏的状态转移图](F:\develop\xcpc\src\topics\game-theory\sg-function\assets\取子游戏的状态转移图.png)

* 后继结点：当前节点能一步到达的节点

* sg(x)就是求对于当前节点的所有后继结点，去除这些后继结点的sg值后最小的非负整数

  >例如上图中
  >
  >* 0作为终结点，没有后继，选取最小的非负整数 => 0
  >* 1的后继为0，去除0的最小的非负整数 => 1
  >* 2 => 2
  >* 3 => 3
  >* 4的后继为1,2,3，而1,2,3的sg值分别为1,2,3，则去除1,2,3的最小非负整数 => 0
  >* 5的后继为2,3,4，而2,3,4的sg值分别为2,3,0，则去除2,3,0的最小非负整数 => 1

## 应用

![](F:\develop\xcpc\src\topics\game-theory\sg-function\assets\SG函数的使用.png)

>证明：
>
>对于终结点，sg值为0，必败点
>
>对于一步能走到sg为0的点，sg值一定不为0（因为0被占了），必胜点
>
>对于只能走到sg值为非0的点，sg值一定为0（因为0没被占），必败点
>
>故满足必胜必败点属性