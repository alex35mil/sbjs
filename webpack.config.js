const webpack = require('webpack');
const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const ExtractTextPlugin = require('extract-text-webpack-plugin');
const GzipPlugin = require('compression-webpack-plugin');

module.exports = {
  entry: {
    app: ['./src/App.re', './src/styles/index.css'],
  },
  output: {
    path: path.join(__dirname, 'docs'),
    filename: '[name].[chunkhash].js',
  },
  context: process.cwd(),
  resolve: {
    extensions: ['.re', '.ml', '.js'],
  },
  devtool: false,
  module: {
    noParse: /\.min\.js$/,
    rules: [
      { test: /\.(re|ml)$/, use: 'bs-loader' },
      {
        test: /\.css$/,
        use: ExtractTextPlugin.extract({
          fallback: 'style-loader',
          use: [
            {
              loader: 'css-loader',
              options: {
                minimize: true,
                importLoaders: 1,
              },
            },
            {
              loader: 'postcss-loader',
              options: {
                ident: 'postcss',
                plugins: () => [
                  require('postcss-import')({
                    path: [__dirname, path.join(__dirname, 'node_modules')],
                  }),
                  require('autoprefixer')(),
                  require('postcss-custom-media')(),
                  require('postcss-custom-properties')(),
                  require('postcss-nesting')(),
                ],
              },
            },
          ],
        }),
      },
      {
        test: /\.md$/,
        use: [
          {
            loader: 'html-loader',
            options: {
              minimize: true,
            },
          },
          {
            loader: 'markdown-loader',
            options: {
              gfm: true,
              breaks: true,
              smartypants: true,
            },
          },
        ],
      },
    ],
  },
  plugins: [
    new ExtractTextPlugin({
      filename: '[name].[contenthash].css',
      allChunks: true,
    }),
    new webpack.optimize.UglifyJsPlugin({
      compress: {
        drop_debugger: true,
        drop_console: true,
        screw_ie8: true,
        warnings: false,
      },
    }),
    new GzipPlugin({
      asset: '[path].gz',
      algorithm: 'gzip',
      regExp: /\.js$|\.css$/,
    }),
    new HtmlWebpackPlugin({
      template: './src/statics/index.ejs',
      favicon: './src/statics/favicon.ico',
      inject: 'body',
      minify: {
        html5: true,
        collapseWhitespace: true,
        preserveLineBreaks: false,
      },
    }),
  ],
};
