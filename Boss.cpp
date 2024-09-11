#include "Boss.h"
#include <cmath>

Boss::Boss(sf::Vector2f size, sf::Vector2f position, float speed) :
    Enemy(size, position, speed)
{
    this->boss.setPosition(position);
    this->boss.setSize(size);
    this->speed = speed;
    this->velocity.x = speed;
    this->boss.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

    this->boss.setFillColor(sf::Color::Magenta);
    this->currentAttack = None;
    std::srand(std::time(0));
    this->gravity = 800.0f;
    this->jumpCount = 0;
    this->isJumping = false;
    this->attackInterval = sf::seconds(2); // Intervalo entre os ataques
}

void Boss::update(float dt, sf::Vector2f playerPosition)
{
    std::cout << "X: " << boss.getPosition().x << "Y: " << boss.getPosition().y << std::endl;
    // Escolhe o próximo ataque após o intervalo
    if (attackTimer.getElapsedTime() > attackInterval)
    {
        chooseNextAttack();
        attackTimer.restart();
    }

    if (currentAttack == Jump)
    {
        handleJump(dt);
    }
    else if (currentAttack == Shoot)
    {
        shootProjectiles(dt);
    }
    else
    {
        // Caminhar em direção ao player
        if (playerPosition.x > this->boss.getPosition().x)
        {
            velocity.x = speed;
        }
        else
        {
            velocity.x = -speed;
        }
    }

    applyGravity(dt);
    //this->boss.move(velocity * dt);

    // Reseta a posição inicial no eixo y após os 3 pulos
    if (isJumping && boss.getPosition().y >= initialPosition.y)
    {
        resetJump();
    }
}

void Boss::render(sf::RenderWindow& window)
{
    window.draw(this->boss);

    // Renderizar projéteis
    for (auto& projectile : projectiles)
    {
        window.draw(projectile);
    }
}

void Boss::jumpAttack(sf::Vector2f playerPosition)
{
    if (jumpCount < 3)
    {
        this->isJumping = true;
        this->jumpCount++;
        this->targetPosition = playerPosition;
        this->velocity.y = -400.0f;  // Velocidade inicial do pulo
        this->currentAttack = Jump;
    }
}

void Boss::shootProjectiles(float dt)
{
    if (projectiles.empty())
    {
        // Cria os projéteis e define a direção deles
        for (int i = 0; i < 5; i++)
        {
            sf::CircleShape projectile(5.0f);
            projectile.setFillColor(sf::Color::Yellow);
            projectile.setPosition(boss.getPosition());

            sf::Vector2f direction;

            switch (i)
            {
            case 0: direction = sf::Vector2f(1, 0); break;  // Direita
            case 1: direction = sf::Vector2f(-1, 0); break; // Esquerda
            case 2: direction = sf::Vector2f(0, -1); break; // Cima
            case 3: direction = sf::Vector2f(0, 1); break;  // Baixo
            case 4: direction = sf::Vector2f(1, 1); break;  // Diagonal
            }

            projectile.move(direction * speed * dt * 10.0f);  // Ajuste de velocidade
            projectiles.push_back(projectile);
        }
    }

    // Movimentação dos projéteis
    for (auto& projectile : projectiles)
    {
        sf::Vector2f direction = projectile.getPosition() - boss.getPosition();
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0)
        {
            direction /= length;  // Normaliza a direção
            projectile.move(direction * speed * dt * 300.0f);
        }
    }

    // Remoção dos projéteis após percorrerem uma certa distância
    if (!projectiles.empty() && projectiles[0].getPosition().x > 800.0f) // Exemplo de distância
    {
        projectiles.clear();
        currentAttack = None;
    }
}

void Boss::applyGravity(float dt)
{
    if (isJumping)
    {
        velocity.y += gravity * dt;
    }
    else
    {
        velocity.y = 0;
    }
}

void Boss::resetJump()
{
    velocity.y = 0;
    boss.setPosition(boss.getPosition().x, initialPosition.y);
    isJumping = false;

    if (jumpCount >= 3)
    {
        jumpCount = 0;
        currentAttack = None;
    }
}

void Boss::handleJump(float dt)
{
    if (isJumping)
    {
        velocity.x = (targetPosition.x - boss.getPosition().x) > 0 ? speed : -speed;
    }
}

void Boss::chooseNextAttack()
{
    int randomAttack = std::rand() % 2;

    if (randomAttack == 0 && jumpCount == 0)  // Inicia um ataque de pulo
    {
        jumpAttack(initialPosition);  // O boss pula na direção do jogador
    }
    else  // Atira projéteis
    {
        currentAttack = Shoot;
    }
}
