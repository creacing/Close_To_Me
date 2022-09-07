<template>
  <div id="sidebar" :class="isSidebar ? 'on sidebar-show' : ''">
    <div class="inner">
      <div class="panels">
        <div class="inner">
          <div class="contents panel pjax" data-title="文章目录"></div>
          <div class="related panel pjax" data-title="系列文章"></div>
          <div class="overview panel active" data-title="站点概览">
            <div class="author" itemprop="author" itemscope itemtype="http://schema.org/Person">
              <img
                class="image lozaded"
                itemprop="image"
                alt="Ruri Shimotsuki"
                :data-src="sidebar.avator"
                :src="sidebar.avator"
                data-loaded="true"
              />
              <p class="name" itemprop="name">{{ sidebar.author }}</p>
              <div class="description" itemprop="description">{{ sidebar.description }}</div>
            </div>
            <nav class="state">
              <div class="item posts">
                <router-link to="/archives/" data-pjax-state>
                  <span class="count">{{ sidebar.articlesNum }}</span>
                  <span class="name">文章</span>
                </router-link>
              </div>
              <div class="item categories">
                <router-link to="/categories/" data-pjax-state>
                  <span class="count">{{ sidebar.categoriesNum }}</span>
                  <span class="name">分类</span>
                </router-link>
              </div>
              <div class="item tags">
                <router-link to="/tags/" data-pjax-state>
                  <span class="count">{{ sidebar.tagsNum }}</span>
                  <span class="name">标签</span>
                </router-link>
              </div>
            </nav>
            <div class="social">
              <router-link
                v-for="link of sidebar.socialLinks"
                :key="link"
                :to="link.url"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item"
                :class="link.name"
                :title="link.url"
              >
                <i class="ic" :class="link.icon"></i>
              </router-link>
            </div>
            <ul class="menu">
              <li class="item" v-for="link in nav" :class="link.liClass" :key="link">
                <router-link :to="link.link" data-pjax-state v-if="link.children.length === 0">
                  <i class="ic" :class="link.iClass" v-if="link.iClass"></i>
                  {{ link.name }}
                </router-link>
                <span data-pjax-state v-else>
                  <i class="ic" :class="link.iClass" v-if="link.iClass"></i>
                  {{ link.name }}
                </span>
                <ul class="submenu" v-if="link.children.length > 0">
                  <li class="item" v-for="subLink in link.children" :key="subLink">
                    <router-link :to="subLink.link" rel="section" data-pjax-state>
                      <i class="ic" :class="subLink.iClass"></i>
                      {{ subLink.name }}
                    </router-link>
                  </li>
                </ul>
              </li>
            </ul>
          </div>
        </div>
      </div>
      <ul id="quick">
        <li class="prev pjax"></li>
        <li class="up">
          <i class="ic i-arrow-up"></i>
        </li>
        <li class="down">
          <i class="ic i-arrow-down"></i>
        </li>
        <li class="next pjax">
          <a href="/page/2/" rel="next" title="下一篇" data-pjax-state>
            <i class="ic i-chevron-right"></i>
          </a>
        </li>
        <li class="percent" style="width: 16%"></li>
      </ul>
    </div>
  </div>
</template>
<script setup>
import { toRefs } from "vue";
import config from "../../public/config";
import { store } from "@/stores/store.js";
import anime from "animejs/lib/anime.es.js";
import { RouterLink } from "vue-router";
const { nav, sidebar } = config;
const state = store();
const { isSidebar } = toRefs(state);
</script>

<style lang='scss' scoped>
.panels {
  padding-top: 0.625rem;
}

@media (min-width: 991px) {
  #sidebar {
    position: sticky;
    top: 0;
    transform: translateX(0) !important;
    opacity: 1 !important;
    display: block !important;
  }
}
#sidebar > .inner {
  height: 100%;
}

#sidebar > .inner > .panels {
  height: calc(100% - 0.625rem);
}
#sidebar > .inner > .panels > .inner {
  height: 100%;
}
</style>