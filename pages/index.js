import Index from './Index.re';
import PropTypes from 'prop-types';
import React, { Component } from 'react';
import * as status from '../lib/js/utils/Status';
import { fetchListings } from '../utils/endpoints';

const _buildErrorProps = error => ({
  error,
  status: status.error,
});

export default class IndexPage extends Component {
  static async getInitialProps() {
    const defaultProps = { status: status.idle, items: [], error: {} };

    // Disable fetch for server render
    if (typeof window === 'undefined') {
      let resp, json;
      try {
        resp = await fetchListings();
      } catch (err) {
        return { ...defaultProps, ..._buildErrorProps(err) };
      }

      if (resp.ok) {
        try {
          json = await resp.json();
        } catch (err) {
          return { ...defaultProps, ..._buildErrorProps(err) };
        }
      } else {
        return {
          ...defaultProps,
          error: { message: 'Failure' },
          status: status.error,
        };
      }

      return {
        ...defaultProps,
        status: status.fetched,
        items: json.results,
      };
    }

    return defaultProps;
  }

  render() {
    return (
      <Index
        status={this.props.status}
        items={this.props.items}
        error={this.props.error}
      />
    );
  }
}

IndexPage.propTypes = {
  status: PropTypes.string,
  items: PropTypes.array,
  error: PropTypes.object,
};
