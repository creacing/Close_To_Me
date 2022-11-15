<template>
  <div class="site flex-row">
    <div class="item" :title="site.title" v-for="site in sites" :key="site">
      <div class="info">
        <a
          class="title"
          target="_blank"
          :href="site.url"
          :title="site.title"
          rel="noopener external nofollow noreferrer"
        >{{site.title}}</a>
        <p class="desc">{{site.description}}</p>
      </div>
    </div>
  </div>
</template>
<script setup>
import config from "../../public/config";
const { sites } = config
</script>

<style lang="scss" scoped>
.site {
  flex-wrap: wrap;
  font-size: 0.9rem;
  .item {
    line-height: 1.5;
    width: calc(50% - 2rem);
    padding: 0.5rem 1rem;
    margin: 1rem;
    transition: all 0.2s ease-in-out 0s;
    border-radius: 0.5rem;
    border: 0.0625rem solid var(--grey-2);
    box-shadow: 0 0.625rem 1.875rem -0.9375rem var(--box-bg-shadow);
    --bg-color: var(--block-color, #666);
    .info {
      padding-left: 1rem;
    }

    .title {
      margin: 0.5rem 0;
      font-family: Mulish, "Noto Serif JP", "Noto Serif SC", Mulish,
        -apple-system, "PingFang SC", "Microsoft YaHei", sans-serif;
      font-weight: 700;
      color: var(--bg-color);
      border: none;
      .ic {
        display: none;
      }
    }

    .desc {
      font-size: 0.75em;
      margin: 0.5rem 0;
    }
  }
  .item:hover {
    color: var(--header-text-color);
    background-color: var(--bg-color);
    box-shadow: 0 0.125rem 1.25rem var(--bg-color);
    border-color: var(--bg-color);
    .title {
      color: var(--header-text-color);
    }
  }
}

@media (max-width: 767px) {
  .site {
    font-size: 1em;
    .item {
      width: calc(100% - 2rem);
    }
  }
}
</style>