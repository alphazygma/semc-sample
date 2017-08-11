// Object to act as Enum for roles
var roleEnum = {
    ROAM    : 'Captain',
    CARRY   : 'Carry',
    JUNGLER : 'Jungler'
}

// Object to act as Enum for offense types
var offenseEnum = {
    MELEE : 'Melee',
    RANGE : 'Ranged'
}

// Object to act as Enum for difficulties
var difficultyEnum = {
    EASY   : 'Easy',
    MEDIUM : 'Medium',
    HARD   : 'Hard'
}

// Map that contains the definition of the characters
var avatarMap = {
    alpha: {
        name       : 'Alpha',
        image      : 'images/banner_alpha.png',
        role       : roleEnum.JUNGLER,
        offense    : offenseEnum.MELEE,
        difficulty : difficultyEnum.HARD
    },
    ardan: {
        name       : 'Ardan',
        image      : 'images/banner_ardan.png',
        role       : roleEnum.ROAM,
        offense    : offenseEnum.MELEE,
        difficulty : difficultyEnum.EASY
    },
    idris: {
        name       : 'Idris',
        image      : 'images/banner_idris.png',
        role       : roleEnum.CARRY,
        offense    : offenseEnum.MELEE,
        difficulty : difficultyEnum.HARD
    },
    grace: {
        name       : 'Grace',
        image      : 'images/banner_grace.png',
        role       : roleEnum.ROAM,
        offense    : offenseEnum.MELEE,
        difficulty : difficultyEnum.EASY
    },
    rona: {
        name       : 'Rona',
        image      : 'images/banner_rona.png',
        role       : roleEnum.JUNGLER,
        offense    : offenseEnum.MELEE,
        difficulty : difficultyEnum.MEDIUM
    },
    skaarf: {
        name       : 'Skaarf',
        image      : 'images/banner_skaarf.png',
        role       : roleEnum.CARRY,
        offense    : offenseEnum.RANGE,
        difficulty : difficultyEnum.EASY
    }
}

/**
 * Obtain the Avatar's name given its ID
 * @param {String} avatarId The Identifier for the avatar
 * @returns {String} The name of the Avatar
 */
function getName(avatarId) {
    var avatarObj = avatarMap[avatarId];
    return avatarObj.name;
}

/**
 * Obtain the Avatar's banner image given its ID
 * @param {String} avatarId The Identifier for the avatar
 * @returns {String} The image path for the Avatar's banner
 */
function getImage(avatarId) {
    var avatarObj = avatarMap[avatarId];
    return avatarObj.image;
}

/**
 * Obtain the Avatar's role given its ID
 * @param {String} avatarId The Identifier for the avatar
 * @returns {String} The role for the Avatar
 */
function getRole(avatarId) {
    var avatarObj = avatarMap[avatarId];
    return avatarObj.role;
}

/**
 * Obtain the Avatar's offense given its ID
 * @param {String} avatarId The Identifier for the avatar
 * @returns {String} The Avatar's offense
 */
function getOffense(avatarId) {
    var avatarObj = avatarMap[avatarId];
    return avatarObj.offense;
}

/**
 * Obtain the Avatar's play difficulty given its ID
 * @param {String} avatarId The Identifier for the avatar
 * @returns {String} The Avatar's play difficulty
 */
function getDifficulty(avatarId) {
    var avatarObj = avatarMap[avatarId];
    return avatarObj.difficulty;
}
