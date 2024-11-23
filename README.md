# AutomatedProving
2024 ETU Math Logic colloquium.  Automated prover.

| Участник      | Задание |
|---------------|---------|
| Поглазов Н.В. |    1    |
| Вовченко С.Е. |    2    |
| Валеева А.А.  |    3    |
| Кузьииных Е.М |    4    |


# 3 задание. Аналог метода резолюций
Данный алгоритм применяется, когда посылки имеют вид формул, включающих только импликации и отрицания.

### Использующиеся правила:
1. Правило транзитивности импликации:
   
$$P → Q, Q → R, ⊢ P → R$$  

2. Перестановка импликаций:  

$$ P → Q \iff \neg P ∨ Q \iff Q ∨ \neg P \iff \neg Q → \neg P $$

### Алгоритм

1.
$$
\begin{aligned}
    & \begin{array}{c}
        A \lor B \\
        A \lor \neg B \\
        \hline
        \vdash A
    \end{array}
    \hspace{1cm} % расстояние между столбцами
    \begin{array}{c}
       \iff \neg A → B \\
       \iff \neg A → \neg B \\
       \hline
       \
     \end{array}
     \hspace{1cm} % расстояние между столбцами
     swap 
    \begin{array}{c}
        \neg A → B \\
        B → A \\
        \hline
        \vdash A
    \end{array}
    \hspace{1cm} % расстояние между столбцами
        \begin{array}{c}
         (транзитивность)
        \neg A → B, B → A, \vdash \neg A → A \iff \vdash A
    \end{array}
\end{aligned}
$$


2.
$$
\begin{aligned}
    & \begin{array}{c}
        A \lor B \\
        \neg A \lor B \\
        \hline
        \vdash B
    \end{array}
    \hspace{1cm} % расстояние между столбцами
    \begin{array}{c}
       \iff \neg A → B \\
       \iff A → B \\
       \hline
       \
     \end{array}
     \hspace{1cm} % расстояние между столбцами
     \begin{array}{c}
        \neg B → A \\
        A → B \\
        \hline
        \vdash B
    \end{array}
    \hspace{1cm} % расстояние между столбцами
        \begin{array}{c}
        \neg B → A, A → B, \vdash \neg B → B \iff \vdash B
    \end{array}
\end{aligned}
$$

3.
$$
\begin{aligned}
    & \begin{array}{c}
        A \lor \neg B \\
        \neg A \lor \neg B \\
        \hline
        \vdash \neg B
    \end{array}
    \hspace{1cm} % расстояние между столбцами
    \begin{array}{c}
       \iff \neg A → \neg B \\
       \iff A → \neg B \\
       \hline
       \
     \end{array}
     \hspace{1cm} % расстояние между столбцами
     \begin{array}{c}
        B → A \\
        A → \neg B \\
        \hline
        \vdash \neg B
    \end{array}
    \hspace{1cm} % расстояние между столбцами
        \begin{array}{c}
        B → A, A → \neg B, \vdash B → \neg B \iff \vdash  \neg B
    \end{array}
\end{aligned}
$$

4.
$$
\begin{aligned}
    & \begin{array}{c}
        \neg A \lor B \\
        \neg A \lor \neg B \\
        \hline
        \vdash \neg A
    \end{array}
    \hspace{1cm} % расстояние между столбцами
    \begin{array}{c}
       \iff A → B \\
       \iff A → \neg B \\
       \hline
       \
     \end{array}
     \hspace{1cm} % расстояние между столбцами
     \begin{array}{c}
        A → B \\
        B → \neg A \\
        \hline
        \vdash \neg A
    \end{array}
    \hspace{1cm} % расстояние между столбцами
        \begin{array}{c}
        A → B, B → \neg A, \vdash A → \neg A \iff \vdash  \neg A
    \end{array}
\end{aligned}
$$

## Пример использования метода
$$ P → Q, \neg Q, \vdash \neg P  $$

Логика: 
импликация $$\( P \to Q \)$$ истинна, если P - ложно (то есть $$\( \neg P \))$$ или Q - истинно). 
Но вторая посылка истинна, то есть $$\( \neg Q \)$$  - истинно, а Q - ложно. 
Следовательно, достаточно $$\( \neg P \)$$.
