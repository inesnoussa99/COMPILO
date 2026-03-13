#pragma once

/**
 * type.h — Types de base du compilateur ifcc.
 *
 * Pour l'instant on ne supporte que int (32 bits).
 * On garde une enum pour préparer l'ajout futur de char, double, void…
 */
enum class Type {
    INT,    ///< entier 32 bits (int)
    VOID,   ///< type de retour void (fonctions futures)
    CHAR,   ///< entier 8 bits (futur)
};

/// Taille en octets d'un type
inline int typeSize(Type t) {
    switch (t) {
        case Type::INT:  return 4;
        case Type::CHAR: return 1;
        case Type::VOID: return 0;
    }
    return 4;
}

/// Suffixe d'instruction x86 selon le type (l=32bit, b=8bit…)
inline char typeSuffix(Type t) {
    switch (t) {
        case Type::CHAR: return 'b';
        default:         return 'l';
    }
}

/// Nom du registre accumulateur selon le type
inline const char* accReg(Type t) {
    switch (t) {
        case Type::CHAR: return "%al";
        default:         return "%eax";
    }
}