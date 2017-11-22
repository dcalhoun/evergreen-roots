import ErrorMessage from '../components/ErrorMessage';
import EtsyListings from '../containers/EtsyListings';
import Head from 'next/head';
import Listings from '../components/Listings';
import Loading from '../components/Loading';
import PropTypes from 'prop-types';
import React, { Component } from 'react';
import { fetchListings } from '../utils/endpoints';

class Index extends Component {
  static async getInitialProps() {
    const resp = await fetchListings();
    const json = await resp.json();
    return { items: json.results };
  }

  render() {
    return (
      <div>
        <Head>
          <title>Evergreen Roots</title>
          <meta
            name="viewport"
            content="initial-scale=1.0, width=device-width"
          />
        </Head>
        {/* TODO: Lose EtsyListings altogether now that it's server rendered? */}
        <EtsyListings items={this.props.items}>
          {({ error, isFetching, items }) =>
            error ? (
              <ErrorMessage title={error} />
            ) : isFetching ? (
              <Loading />
            ) : (
              <Listings items={items} />
            )
          }
        </EtsyListings>
      </div>
    );
  }
}

Index.displayName = 'Index';

Index.propTypes = {
  items: PropTypes.array,
};

export default Index;
