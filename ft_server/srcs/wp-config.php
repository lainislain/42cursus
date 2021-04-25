<?php
/**
 * The base configuration for WordPress
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_db' );

/** MySQL database username */
define( 'DB_USER', 'lain' );

/** MySQL database password */
define( 'DB_PASSWORD', 'lainislain' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'oV5fy&v02[RQC{K,kZ?fLhd9;|pN.B;4Ic,4H_xSHU|lWAtbc&t@s+hX izM(!+|');
define('SECURE_AUTH_KEY',  '%+dvon;9|-uWYpcs}}wK&-5A8)+RD}7xj/++-)fNlHv#(]XQXwsU c-,sa20f*:9');
define('LOGGED_IN_KEY',    'O[M/FfFRb;[h$F,NH,^=55A{2.uE@eno<n{xmSeAbaK0}u4bXr!(0A4^7Npu.z3:');
define('NONCE_KEY',        'qf9VWx=YX:mV|-sdsy{[B&zD$4G6-/9EM~/K@9x0>2VLiVDa8&5&Veek?--Cu Vh');
define('AUTH_SALT',        'fhZid;2sl$rxO1v..VN@yku9[Mi-oMNHCC%$L4;$=S:->[*j|zL#g+&&aVlH;-wB');
define('SECURE_AUTH_SALT', 'R8nGT~OwNbto`WZvF?RYVq=,$uT`zG3`9q_7f!#?MeMv [*yn:ebGR+J|iw&2zs>');
define('LOGGED_IN_SALT',   'HxRQV0k-2|JN1Dw&s<kI[44>&_w$bFEJOwCKMfBiXy$2Fn:^Qh6I[>5bi=.ndmFD');
define('NONCE_SALT',       'W#Sf6MQ(S/hFKd*R<g?Cu,?<{#5uUfbz5WR`gIz;]Fatg87lCmtuR#mf,}*|*rd$');/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 *  * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
