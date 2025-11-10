# Holiday Recommendation System Using Markov Chains

A simple recommendation system for Indonesian tourism destinations using **Markov chains** combined with **age-based collaborative filtering** and **budget awareness**. This project was developed as part of the **Artificial Intelligence (1DL340)** course at **Uppsala University**.

**Authors**: Gabrielle Fidelis de Castilho, Hemavathi Hanasoge Siddaiah, Kim Kuruvilla Mathews

---

## 📌 Overview
This system suggests tourist attractions based on:
- **User visit history**
- **Age group preferences**
- **Spending patterns**
- **Destination ratings**

The main idea:
- Use **Markov chains** to predict the next category of attraction (e.g., Culture → Natural Reserve).
- Rank places within that category using **collaborative filtering by age** and **budget constraints**.

---

## ✅ Features
- **Markov Chain Category Prediction**: Calculates transition probabilities between attraction categories.
- **Age-Based Collaborative Filtering**: Prioritizes places rated highly by users in the same age range.
- **Budget Awareness**: Filters out places that cost more than twice the user’s average spending.
- **Visit History Tracking**: Avoids recommending places the user has already visited.
- **Cold Start Handling**: For new users, assigns equal probabilities to all categories.
- **Multi-City Support**: Works for Jakarta, Yogyakarta, Semarang, Bandung, and Surabaya.

---

## 📂 Dataset
We use the [Indonesia Tourism Destination dataset(mirrored on GitHub for convenience):
- **437 attractions** across 5 cities
- **300 users** with age and location info
- **10,000 ratings**

---

## 🔧 Installation
### Prerequisites
- Python 3.7+
- Install required libraries:
```bash
pip install pandas numpy scikit-learn