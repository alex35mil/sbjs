const HtmlWebpackPlugin = require('html-webpack-plugin');
const ExtractTextPlugin = require('extract-text-webpack-plugin');
const path = require('path');

module.exports = {
  entry: {
    app: ['./src/App.re', './src/styles/index.css'],
  },
  output: {
    path: path.join(__dirname, 'public'),
    filename: '[name].js',
  },
  resolve: {
    extensions: ['.re', '.ml', '.js'],
  },
  module: {
    rules: [
      { test: /\.(re|ml)$/, use: 'bs-loader' },
      {
        test: /\.css$/,
        use: ExtractTextPlugin.extract({
          fallback: 'style-loader',
          use: 'css-loader',
        }),
      },
    ],
  },
  plugins: [
    new ExtractTextPlugin({
      filename: 'styles.css',
      allChunks: true,
    }),
    new HtmlWebpackPlugin({
      inject: 'body',
      template: './src/statics/index.ejs',
      minify: {
        html5: true,
        collapseWhitespace: true,
        preserveLineBreaks: false,
      },
    }),
  ],
};
