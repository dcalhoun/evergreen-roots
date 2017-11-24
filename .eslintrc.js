module.exports = {
  extends: [
    'standard',
    'plugin:react/recommended',
    'prettier',
    'prettier/standard',
  ],
  plugins: ['prettier', 'react'],
  parser: 'babel-eslint',
  parserOptions: {
    ecmaFeatures: {
      jsx: true,
    },
  },
  rules: {
    'prettier/prettier': ['error', { singleQuote: true, trailingComma: 'es5' }],
    strict: 0,
  },
};
